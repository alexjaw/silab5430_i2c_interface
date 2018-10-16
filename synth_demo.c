/**
 * Demo for Si5340D programming and frequency manipulation
 * Communication using I2C
* */
#include <stdio.h>  //perror, printf
#include <fcntl.h>  //open
#include <sys/ioctl.h>  //ioctl
#include <linux/i2c-dev.h>  //I2C_SLAVE
#include <unistd.h> //read, write, close, sleep, usleep
#include <stdint.h>  //uintX_t

#include "synth_config.h"
#include "441_delta.h"
#include "48_delta.h"

#define PAGE              0x01
#define END_PREAMBLE_REG  5
#define PREAMBLE_SLEEP    300000
#define SYNTH_ADDR        0x74

int file;
const char *device = "/dev/i2c-1";

typedef struct
{
    uint8_t page; /* 8-bit register page address */
    uint8_t reg; /* 8-bit register addresss */

} synth_regaddr_t;

/* Extract 8-bit page and register address from 16-bit register address */
synth_regaddr_t get_reg_addr(synth_register_t si_register) {
    uint8_t page = si_register.address >> 8; //MSB is page
    uint8_t reg = si_register.address;  //LSB is register
    synth_regaddr_t regaddr = { page, reg};
    return regaddr;
}

/* Init i2c and set up i2c slave */
int synth_init() {
    if ((file = open(device, O_RDWR)) < 0) {
        perror("failed to open the bus\n");
        return 1;
    }

    // Set i2c slave addr
    if(ioctl(file, I2C_SLAVE, SYNTH_ADDR) < 0){
        perror("Failed to set slave device addr\n");
        return 1;
    }
    return 0;
}

int synth_close() {
    close(file);
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
    if (write(file, buffer, 2) != 2) {
        perror("Failed to set page\n");
        return 1;
    }

    // A. Write register value
    //buffer[0] = reg;
    buffer[0] = regaddr.reg;
    buffer[1] = val;
    if (write(file, buffer, 2) != 2) {
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
            close(file);
            return 1;
        }
        if (i == END_PREAMBLE_REG) {
            usleep(PREAMBLE_SLEEP);  // See documentation Si5340D
        }
    }
    return 0;
}

/* Read data from one register */
int synth_read_register(synth_register_t si_register) {
    //uint8_t page = get_page(si_register.address);
    //uint8_t reg = get_reg(si_register.address);
    synth_regaddr_t regaddr = get_reg_addr(si_register);
    uint8_t val = si_register.value;
    uint8_t buffer[2] = {0};

    // On si3540, before we can access a register, we must set the page
    buffer[0] = PAGE;
    //buffer[1] = page;
    buffer[1] = regaddr.page;
    if (write(file, buffer, 2) != 2) {
        perror("Failed to set page\n");
        return 1;
    }

    // A. Write register
    //buffer[0] = reg;
    buffer[0] = regaddr.reg;
    if (write(file, buffer, 1) != 1) {
        perror("Failed to set register\n");
        return 1;
    }

    // A. Read register
    buffer[0] = 0;
    if (read(file, buffer, 1) != 1) {
        perror("Failed to read register\n");
        return 1;
    }
    if (buffer[0] != val) {
        perror("Wrong register value found.");
        printf("reg:  0x%04x\n", si_register.address);
        printf("sent: 0x%02x\n", val);
        printf("recv: 0x%02x\n", buffer[0]);
        return 1;
    }

    return 0;
}

/* TBD Read array of register data */
int synt_read_registers() {
    return 1;
}

int main(void) {
    printf("Starting Si5340D demo\n");
    synth_init();

    // Write full synth configuration
    printf("Writing full configuration\n");
    synth_write_registers(synth_registers, SYNTH_REG_CONFIG_NUM_REGS);

    //verify, but skip preamble and postamble
    /*for (int i = 0; i < SYNTH_REG_CONFIG_NUM_REGS; ++i) {
        //printf("0x%04x, 0x%02x\n",
        //        synth_registers[i].address,
        //        synth_registers[i].value);
        if ((i > 5) && (i < SYNTH_REG_CONFIG_NUM_REGS - 3)) {
            if (synth_read_register(synth_registers[i]) != 0){
                perror("Verification failed");
                printf("failed at register %i\n", i);
                close(file);
                return 1;
            }
        }
    }*/

    //change XMOS OUT2 44.1k*512 -> 48k*512
    sleep(5);
    printf("Changing OUT2 44.1k*512 -> 48k*512\n");
    synth_write_registers(synth_registers_delta_48, DELTA_48_CONFIG_NUM_REGS);

    //change XMOS OUT2 48k*512 -> 44.1k*512
    sleep(5);
    printf("Changing back 48k*512 -> 44.1k*512\n");
    synth_write_registers(synth_registers_delta_441, DELTA_441_CONFIG_NUM_REGS);

    synth_close();
    printf("Demo finished.\n");
    return 0;
}

