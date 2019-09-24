//
// Created by alexander on 2019-09-24.
//

#ifndef SILAB5430_I2C_INTERFACE_SYNTH_H
#define SILAB5430_I2C_INTERFACE_SYNTH_H

#include <stdint.h>
#include "synth_config.h"

#define PAGE              0x01
#define END_PREAMBLE_REG  5
#define PREAMBLE_SLEEP    300000  //us. Works down to 50000us
#define SYNTH_ADDR        0x77//0x74

typedef struct
{
    uint8_t page; /* 8-bit register page address */
    uint8_t reg; /* 8-bit register addresss */

} synth_regaddr_t;

int synth_init();
int synth_close();
int synth_write_register(synth_register_t si_register);
int synth_write_registers(synth_register_t const synth_registers[], int const n_regs);

#endif //SILAB5430_I2C_INTERFACE_SYNTH_H
