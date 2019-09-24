//
// Created by alexander on 2019-09-24.
//

#ifndef SILAB5430_I2C_INTERFACE_I2C_H
#define SILAB5430_I2C_INTERFACE_I2C_H

int i2cOpen(void);
int i2cClose(void);
int write_i2c_block_data_raw(unsigned char addr, unsigned char *buf, unsigned short val_len);

#endif //SILAB5430_I2C_INTERFACE_I2C_H
