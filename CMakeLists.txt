cmake_minimum_required(VERSION 3.15)
project(Complex_numbers)

set(CMAKE_CXX_STANDARD 17)
add_executable(Complex_numbers main.cpp complex.cpp complex.h rational.cpp rational.h catch_amalgamated.hpp catch.cpp)