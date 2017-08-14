cmake_minimum_required(VERSION 3.8)
project(test_system)


set(BUILD_1 main)
set(CMAKE_INCLUDE_CURRENT_DIR  ON)
#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#查找Qt的库
find_package(Qt5Widgets)

set(SOURCE_FILES main.cpp Topic_lib.h Topic_lib.cpp getTopic.h mainwindow.cpp
        mainwindow.h mainwindow.ui)

add_executable(test_system ${SOURCE_FILES})
target_link_libraries(test_system Qt5::Widgets)
