cmake_minimum_required(VERSION 3.6)
project(at_home)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Fraction.cpp
        Fraction.h
        w5_at_home.cpp)

add_executable(at_home ${SOURCE_FILES})