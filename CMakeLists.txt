cmake_minimum_required(VERSION 4.3)
project(CXX_InsertionSort_vs_QuickSort_Compare)

set(CMAKE_CXX_STANDARD 20)

add_executable(CXX_InsertionSort_vs_QuickSort_Compare main.cpp
        Headers/InsertionSort.h
        "CPP Files/InsertionSort.cpp")
