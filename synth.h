//
// Created by alexander on 2019-09-24.
//

#ifndef SILAB5430_I2C_INTERFACE_SYNTH_H
#define SILAB5430_I2C_INTERFACE_SYNTH_H

#include <stdint.h>
#include "synth_config.h"

#define SYNTH_ADDR        0x77//0x74

typedef struct
{
    uint8_t page; /* 8-bit register page address */
    uint8_t reg; /* 8-bit register addresss */

} synth_regaddr_t;

int synth_init();
int synth_close();
int synth_write_registers(synth_register_t const synth_registers[], int const n_regs);
uint8_t synth_read_register(synth_register_t si_register);

#endif //SILAB5430_I2C_INTERFACE_SYNTH_H
