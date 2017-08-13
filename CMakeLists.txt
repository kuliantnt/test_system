cmake_minimum_required(VERSION 3.8)
project(test_system)


set(BUILD_1 main)
set(SOURCE_FILES main.cpp Topic_lib.h Topic_lib.cpp getTopic.h)
add_executable(test_system ${SOURCE_FILES})