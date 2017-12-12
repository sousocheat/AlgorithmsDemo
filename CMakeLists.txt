cmake_minimum_required(VERSION 3.9)
project(AlgorithmsDemo C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsDemo main.c Sorting/SortingFunc.c Sorting/SortingFunc.h Helpers.c Helpers.h)