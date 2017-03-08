cmake_minimum_required(VERSION 3.6)
project(at_home)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Contact.cpp
        Contact.h
        w6_at_home.cpp)

add_executable(at_home ${SOURCE_FILES})