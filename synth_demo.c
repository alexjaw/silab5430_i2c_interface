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

int main(void) {
    printf("Starting Si5340D demo\n");
    synth_init();

    // Write full synth configuration
    printf("Writing full configuration\n");
    synth_write_registers(synth_registers, SYNTH_REG_CONFIG_NUM_REGS);
    printf("Configuration finished.\n");
    //return 0;

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

