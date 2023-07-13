cmake_minimum_required(VERSION 3.25)
project(practic_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(practic_1
        include/ipdata.h
        include/ipfuncs.h
        ipdata.c
        ipfuncs.c
        main.c)
