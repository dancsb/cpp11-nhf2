cmake_minimum_required(VERSION 3.13)
project(nhf2)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic -Wdeprecated)

add_executable(nhf2 main.cpp MyArray.cpp MyArray.h)
