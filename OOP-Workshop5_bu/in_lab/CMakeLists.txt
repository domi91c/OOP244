cmake_minimum_required(VERSION 3.6)
project(in_lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Fraction.cpp
        Fraction.h
        w5_in_lab.cpp)

add_executable(in_lab ${SOURCE_FILES})