cmake_minimum_required(VERSION 2.8)
project(yuv)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME} SHARED scaleprocess.cpp colorspace.cpp)
