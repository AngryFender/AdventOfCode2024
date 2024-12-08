cmake_minimum_required(VERSION 3.27)
project(Advent)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_DATA_PATH $ENV{ADVENT_DATA_PATH})

if(NOT CMAKE_DATA_PATH)
    message(FATAL_ERROR "Environment variable ADVENT_DATA_PATH is not set.")
endif()

if(WIN32)
    add_compile_definitions(PATH_SYMBOL="\\\\")
else()
    add_compile_definitions(PATH_SYMBOL="/")
endif()

add_subdirectory(Day1)
add_subdirectory(Day2)
add_subdirectory(Day3)
add_subdirectory(Day4)
add_subdirectory(Day5)

