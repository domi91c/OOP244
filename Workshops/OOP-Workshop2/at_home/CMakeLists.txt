cmake_minimum_required(VERSION 3.6)
project(at_home)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        kingdom.cpp
        kingdom.h
        w2_at_home.cpp)

add_executable(at_home ${SOURCE_FILES})