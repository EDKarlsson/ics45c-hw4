cmake_minimum_required(VERSION 3.6)
project(hw4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    create_script
    instructions.md
    Makefile
    String.cpp
    String.h
    string_test
    string_test.cpp)

add_executable(hw4 ${SOURCE_FILES})