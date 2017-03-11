cmake_minimum_required(VERSION 3.6)
project(clib)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES fib.c)
add_executable(clib ${SOURCE_FILES})
add_library(fib SHARED ${SOURCE_FILES})