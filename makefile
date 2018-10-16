CC = gcc
CFLAGS = -std=gnu99
DEPS = synth_config.h 441_delta.h 48_delta.h

demo_read: $(DEPS) synth_demo_read.c
	gcc $(CFLAGS) synth_demo_read.c -o demo_read

demo: $(DEPS) synth_demo.c
	gcc $(CFLAGS) synth_demo.c -o demo