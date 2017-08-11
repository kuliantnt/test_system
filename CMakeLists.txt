cmake_minimum_required(VERSION 3.8)
project(test_system)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Topic_lib.h Topic_lib.cpp)
add_executable(test_system ${SOURCE_FILES})