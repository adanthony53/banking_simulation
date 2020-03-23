cmake_minimum_required(VERSION 3.15)
project(banking_simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(banking_simulation main.cpp Account.cpp Account.h Date.cpp Date.h)