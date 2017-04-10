cmake_minimum_required(VERSION 3.6)
project(at_home)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        fight.cpp
        fight.h
        Hero.cpp
        Hero.h
        SuperHero.cpp
        SuperHero.h
        w7_at_home.cpp)

add_executable(at_home ${SOURCE_FILES})