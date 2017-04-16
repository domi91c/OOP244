cmake_minimum_required(VERSION 3.6)
project(OOP_Milestone4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
#        01-NPErrHandling.cpp
#        02-NPDisplayTest.cpp
#        03-NPSaveLoad.cpp
#        04-PerErrHandling.cpp
        05-PerDateErrHandling.cpp
#        06-PerDisplayTest.cpp
#        07-PerSaveLoad.cpp
#        ms4tester.cpp
        POS.h
        PosIO.h
        Date.cpp
        Date.h
        Error.cpp
        Error.h
        Item.cpp
        Item.h
        NonPerishable.cpp
        NonPerishable.h
        Perishable.cpp
        Perishable.h)

add_executable(OOP_Milestone4 ${SOURCE_FILES})