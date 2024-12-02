cmake_minimum_required(VERSION 3.27)
project(Advent)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_DATA_PATH $ENV{ADVENT_DATA_PATH})

if(NOT CMAKE_DATA_PATH)
    message(FATAL_ERROR "Environment variable ADVENT_DATA_PATH is not set.")
endif()

add_subdirectory(day1)

