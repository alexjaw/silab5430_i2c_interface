CC = gcc
CFLAGS = -std=gnu99
DEPS = synth_config.h 441_delta.h 48_delta.h

demo: $(DEPS) synth_demo.c
	gcc $(CFLAGS) synth_demo.c -o demo