/**
 * Demo for Si5340D programming and frequency manipulation
 * Communication using I2C
* */
#include <stdio.h>  //perror, printf
#include <stdint.h>  //uintX_t
#include "synth.h"

int main(void) {
    printf("Starting Si5340D reading demo\n");
    uint16_t addr = 0x000b;
    printf("Reading i2c address from Si5340 register\n");
    synth_init();

    synth_register_t reg = {addr, 0};  // the second value is a dummy
    uint8_t value = synth_read_register(reg);
    printf("Value in Si5340 address 0x%04x is 0x%02x\n", addr, value);

    synth_close();
    printf("Demo finished.\n");
    return 0;
}

