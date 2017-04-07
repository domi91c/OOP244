cmake_minimum_required(VERSION 3.6)
project(in_lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    CreditCard.cpp
    CreditCard.h
    w3_in_lab.cpp)

add_executable(in_lab ${SOURCE_FILES})