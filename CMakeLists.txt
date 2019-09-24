cmake_minimum_required(VERSION 3.7)
project(silab5430_i2c_interface)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(synth_demo_read synth_demo_read.c i2c/i2c.c i2c/i2c.h synth.c synth.h synth_config.c 48_delta.c 441_delta.c)

add_executable(synth_demo synth_demo.c i2c/i2c.c i2c/i2c.h synth.c synth.h synth_config.c 48_delta.c 441_delta.c)