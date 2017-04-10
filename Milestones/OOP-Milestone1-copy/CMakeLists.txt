cmake_minimum_required(VERSION 3.6)
project(OOP_Milestone1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        01-DefValTester.cpp
        02-ConstructorTester.cpp
        03-LogicalOperator.cpp
        04-DateErrorHandling.cpp
        05-ErrorTester.cpp
        244_ms1_tester.cpp
        Date.cpp
        Date.h
        Error.cpp
        Error.h
        POS.h)

add_executable(OOP_Milestone1 ${SOURCE_FILES})