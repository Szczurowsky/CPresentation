cmake_minimum_required(VERSION 3.21)
project(cpluspoint)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpluspoint main.cpp utils/console.cpp utils/console.h Slide.cpp Slide.h)
