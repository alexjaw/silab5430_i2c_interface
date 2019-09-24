//
// Created by alexander on 2019-09-24.
//

#ifndef SILAB5430_I2C_INTERFACE_SYNTH_H
#define SILAB5430_I2C_INTERFACE_SYNTH_H

#include <stdint.h>
#include "synth_config.h"
#include "48_delta.h"
#include "441_delta.h"

#define SYNTH_ADDR        0x77//0x74

typedef enum {OUT2=2,} synth_channel_t;
typedef enum {F22M579, F24M576,} synth_freq_t;

typedef struct
{
    uint8_t page; /* 8-bit register page address */
    uint8_t reg; /* 8-bit register addresss */

} synth_regaddr_t;

int synth_init();
int synth_close();
int synth_set_freq(synth_channel_t, synth_freq_t);
uint8_t synth_read_register(synth_register_t si_register);

#endif //SILAB5430_I2C_INTERFACE_SYNTH_H
