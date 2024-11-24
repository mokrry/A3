cmake_minimum_required(VERSION 3.27)
project(A3)

set(CMAKE_CXX_STANDARD 17)

add_executable(A3 main.cpp
        array_generator.h
        helping_functions.h
        sort_tester.h
        array_generator.cpp
        sort_tester.cpp
)
