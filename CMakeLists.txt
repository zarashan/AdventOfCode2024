cmake_minimum_required(VERSION 3.30)
project(AdventOfCode2024)

set(CMAKE_CXX_STANDARD 26)

add_executable(AdventOfCode2024 main.cpp
        Days/one/Advent1_1.cpp
        Days/one/Advent1_1.h
        Days/two/Advent2.cpp
        Days/two/Advent2.h
        Days/three/Advent3.cpp
        Days/three/Advent3.h
        Days/four/Advent4.cpp
        Days/four/Advent4.h
        Days/five/Advent5.cpp
        Days/five/Advent5.h
        Days/DayBase.h
)
