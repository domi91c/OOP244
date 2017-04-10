cmake_minimum_required(VERSION 3.6)
project(OOP_Milestone3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        244_ms3_tester.cpp
        Item.cpp
        Item.h
        POS.h
        posIO.h)

add_executable(OOP_Milestone3 ${SOURCE_FILES})