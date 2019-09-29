//
// Created by alexander on 2019-09-24.
//

#ifndef SILAB5430_I2C_INTERFACE_I2C_H
#define SILAB5430_I2C_INTERFACE_I2C_H

#include <stdint.h>

int i2cOpen(void);
int i2cClose(void);
int write_i2c_block_data_raw(uint8_t addr, uint8_t *buf, uint16_t val_len);

#endif //SILAB5430_I2C_INTERFACE_I2C_H
