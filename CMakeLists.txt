cmake_minimum_required(VERSION 3.7)
project(silab5430_i2c_interface)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(synth_demo_read synth_demo_read.c)

add_executable(synth_demo synth_demo.c)