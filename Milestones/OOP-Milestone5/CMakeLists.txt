cmake_minimum_required(VERSION 3.7)
project(OOP_Milestone5_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Date.cpp
        Date.h
        Error.cpp
        Error.h
        Item.cpp
        Item.h
        NonPerishable.cpp
        NonPerishable.h
        Perishable.cpp
        Perishable.h
        POS.h
        PosApp.cpp
        PosApp.h
        PosAppMain.cpp
        PosIO.h)

add_executable(OOP_Milestone5_master ${SOURCE_FILES})