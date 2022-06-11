cmake_minimum_required(VERSION 3.22)
project(RNG_Guesser)

set(CMAKE_CXX_STANDARD 17)

add_executable(RNG_Guesser main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")
