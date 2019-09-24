/**
 * Demo for Si5340D programming and frequency manipulation
 * Communication using I2C
* */
#include <stdio.h>  //perror, printf
#include <unistd.h> //read, write, close, sleep, usleep

#include "synth_config.h"
#include "441_delta.h"
#include "48_delta.h"
#include "synth.h"

/* Read data from one register */
/*int synth_read_register(synth_register_t si_register) {
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
}*/

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
    printf("Configuration finished.\n");
    return 0;

    //change XMOS OUT2 44.1k*512 -> 48k*512
    printf("Will change OUT2 in 5s\n");
    sleep(5);
    printf("Changing OUT2 44.1k*512 -> 48k*512\n");
    synth_write_registers(synth_registers_delta_48, DELTA_48_CONFIG_NUM_REGS);

    //change XMOS OUT2 48k*512 -> 44.1k*512
    printf("Will change OUT2 in 5s\n");
    sleep(5);
    printf("Changing back 48k*512 -> 44.1k*512\n");
    synth_write_registers(synth_registers_delta_441, DELTA_441_CONFIG_NUM_REGS);

    synth_close();
    printf("Demo finished.\n");
    return 0;
}

