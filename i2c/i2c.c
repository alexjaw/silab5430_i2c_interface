//
// Created by alexander on 2019-09-24.
//

#include <stdio.h>
#include <unistd.h>  //close
#include <fcntl.h>   //open
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include "i2c.h"

#define I2C_BUS "/dev/i2c-1"

// I2C Linux device handle
static int g_i2cFile;

// The onlu porpose of this function is to separate the actual call of OS
// ioctl()
static int send_data(struct i2c_rdwr_ioctl_data* packets) {
    if(ioctl(g_i2cFile, I2C_RDWR, packets) < 0) {
        perror("Unable to send data\n");
        return 1;
    }
    return 0;
}

// open the Linux device
int i2cOpen(){
    g_i2cFile = open(I2C_BUS, O_RDWR);
    if (g_i2cFile < 0) {
        perror("i2cOpen");
        return 1;
    }
    return 0;
}

// close the Linux device
int i2cClose(){
    printf("Closing...\n");
    close(g_i2cFile);
    return 0;
}

int write_i2c_block_data_raw(uint8_t addr, uint8_t *outbuf, uint16_t outbuf_size) {

    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = outbuf_size;
    messages[0].buf   = outbuf;

    packets.msgs  = messages;
    packets.nmsgs = 1;

    return send_data(&packets);
}
