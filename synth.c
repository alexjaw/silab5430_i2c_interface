//
// Created by alexander on 2019-09-24.
//

#include <stdio.h>  //perror, printf
#include <unistd.h> //read, write, close, sleep, usleep
#include "synth.h"
#include "i2c/i2c.h"

/* Extract 8-bit page and register address from 16-bit register address */
static synth_regaddr_t get_reg_addr(synth_register_t si_register) {
    uint8_t page = si_register.address >> 8; //MSB is page
    uint8_t reg = si_register.address;  //LSB is register
    synth_regaddr_t regaddr = { page, reg};
    return regaddr;
}

/* Init i2c and set up i2c slave */
int synth_init() {
    if(i2cOpen()){
        perror("failed to open the bus\n");
        return 1;
    }
    return 0;
}

int synth_close() {
    i2cClose();
    return 0;
}

/* Write data to one register */
int synth_write_register(synth_register_t si_register) {
    //uint8_t page = get_page(si_register.address);
    //uint8_t reg = get_reg(si_register.address);
    synth_regaddr_t regaddr = get_reg_addr(si_register);
    uint8_t val = si_register.value;
    uint8_t buffer[2] = {0};

    // On si3540, before we can access a register, we must set the page
    buffer[0] = PAGE;
    //buffer[1] = page;
    buffer[1] = regaddr.page;
    if(write_i2c_block_data_raw(SYNTH_ADDR, buffer, 2)){
        perror("Failed to set page\n");
        return 1;
    }

    // A. Write register value
    //buffer[0] = reg;
    buffer[0] = regaddr.reg;
    buffer[1] = val;
    if(write_i2c_block_data_raw(SYNTH_ADDR, buffer, 2)){
        perror("Failed to set register\n");
        return 1;
    }
    return 0;
}

/* Write array of register data */
int synth_write_registers(synth_register_t const synth_registers[], int const n_regs) {
    for (int i = 0; i < n_regs; ++i) {
        /*printf("0x%04x, 0x%02x\n",
                synth_registers[i].address,
                synth_registers[i].value);*/
        if (synth_write_register(synth_registers[i]) != 0){
            perror("Programming failed");
            synth_close();
            return 1;
        }
        if (i == END_PREAMBLE_REG) {
            usleep(PREAMBLE_SLEEP);  // See documentation Si5340D
        }
    }
    return 0;
}