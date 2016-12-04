cmake_minimum_required(VERSION 3.5)
project(ElectricFenceTesting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ElectricFenceTesting ${SOURCE_FILES})