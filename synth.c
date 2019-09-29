//
// Created by alexander on 2019-09-24.
//

#include <stdio.h>  //perror, printf
#include <unistd.h> //read, write, close, sleep, usleep
#include "synth.h"
#include "i2c/i2c.h"

#define PAGE              0x01
#define END_PREAMBLE_REG  5
#define PREAMBLE_SLEEP    300000  //us. Works down to 50000us

/* Prototypes */
static synth_regaddr_t get_reg_addr(synth_register_t si_register);
static int write_register(synth_register_t si_register);
static int write_registers(const synth_register_t *synth_regs, int const n_regs);
/**/

/* Extract 8-bit page and register address from 16-bit register address */
static synth_regaddr_t get_reg_addr(synth_register_t si_register) {
    uint8_t page = si_register.address >> 8; //MSB is page
    uint8_t reg = si_register.address;  //LSB is register
    synth_regaddr_t regaddr = { page, reg};
    return regaddr;
}

int synth_close() {
    i2cClose();
    return 0;
}

/* Init i2c and set up i2c slave */
int synth_init() {
    if(i2cOpen()){
        perror("failed to open the bus\n");
        return 1;
    }

    // Write full synth configuration
    printf("Writing full configuration\n");
    write_registers(synth_registers, SYNTH_REG_CONFIG_NUM_REGS);
    printf("Configuration finished.\n");

    return 0;
}

/* Read data from one register */
uint8_t synth_read_register(synth_register_t si_register) {
    //uint8_t page = get_page(si_register.address);
    //uint8_t reg = get_reg(si_register.address);
    synth_regaddr_t regaddr = get_reg_addr(si_register);
    uint8_t buffer[2] = {0};

    // On si3540, before we can access a register, we must set the page
    buffer[0] = PAGE;
    //buffer[1] = page;
    buffer[1] = regaddr.page;
    //if (write(file, buffer, 2) != 2) {
    if(write_i2c_block_data_raw(SYNTH_ADDR, buffer, 2)){
        perror("Failed to set page\n");
        return 1;
    }

    // A. Write register
    //buffer[0] = reg;
    buffer[0] = regaddr.reg;
    //if (write(file, buffer, 1) != 1) {
    if(write_i2c_block_data_raw(SYNTH_ADDR, buffer, 1)){
        perror("Failed to set register\n");
        return 1;
    }

    // A. Read register
    buffer[0] = 0;
    //if (read(file, buffer, 1) != 1) {
    if(write_i2c_block_data_raw(SYNTH_ADDR, buffer, 1)){
        perror("Failed to read register\n");
        return 1;
    }
    return buffer[0];
}

int synth_set_freq(synth_channel_t channel, synth_freq_t freq){
    int err = 0;
    if(channel == OUT2){
        if(freq == F22M579){
            write_registers(synth_registers_delta_441, DELTA_441_CONFIG_NUM_REGS);
        }else if(freq == F24M576){
            write_registers(synth_registers_delta_48, DELTA_48_CONFIG_NUM_REGS);
        }else{
            perror("Unknown frequency\n");
            err = 1;
        }
    }else{
        perror("Only channel OUT2 is implemented\n");
        err = 1;
    }
    return err;
}

/* Write data to one register */
static int write_register(synth_register_t si_register) {
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
static int write_registers(const synth_register_t *synth_regs, int const n_regs) {
    for (int i = 0; i < n_regs; ++i) {
        /*printf("0x%04x, 0x%02x\n",
                synth_registers[i].address,
                synth_registers[i].value);*/
        if (write_register(synth_regs[i]) != 0){
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
