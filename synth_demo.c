/**
 * Demo for Si5340D programming and frequency manipulation
 * Communication using I2C
* */
#include <stdio.h>  //perror, printf
#include <unistd.h> //read, write, close, sleep, usleep
#include "synth.h"

int main(void) {
    printf("Starting Si5340D demo\n");
    synth_init();

    //change XMOS OUT2 44.1k*512 -> 48k*512
    printf("Will change OUT2 in 5s\n");
    sleep(5);
    printf("Changing OUT2 44.1k*512 -> 48k*512\n");
    synth_set_freq(OUT2, F24M576);

    //change XMOS OUT2 48k*512 -> 44.1k*512
    printf("Will change OUT2 in 5s\n");
    sleep(5);
    printf("Changing back 48k*512 -> 44.1k*512\n");
    synth_set_freq(OUT2, F22M579);

    synth_close();
    printf("Demo finished.\n");
    return 0;
}

