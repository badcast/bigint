cmake_minimum_required(VERSION 3.5)

project(BigInteger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-lgmpxx -lgmp")

#find_package(gmp REQUIRED)

add_executable(bigint bigint.hpp main.cpp)

