cmake_minimum_required(VERSION 4.3)
project(CXX_InsertionSort_vs_QuickSort_Compare)

set(CMAKE_CXX_STANDARD 20)

add_executable(CXX_InsertionSort_vs_QuickSort_Compare
        main.cpp
        "CPP Files/InsertionSort.cpp"
        "CPP Files/QuickSort.cpp"
        Headers/QuickSort.h)
