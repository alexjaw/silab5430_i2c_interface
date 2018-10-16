cmake_minimum_required(VERSION 3.12)
project(silab5430_i2c_interface)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(silab5430_i2c_interface
        441_delta.h
        48_delta.h
        makefile
        synth_config.h
        synth_demo.c)
