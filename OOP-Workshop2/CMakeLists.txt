cmake_minimum_required(VERSION 3.6)
project(OOP_Workshop2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        at_home/kingdom.cpp
        at_home/kingdom.h
        at_home/w2_at_home.cpp)
#        in_lab/kingdom.cpp
#        in_lab/kingdom.h
#        in_lab/w2_in_lab.cpp)

add_executable(OOP_Workshop2 ${SOURCE_FILES})