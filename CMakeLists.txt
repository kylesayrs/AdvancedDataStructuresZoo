# set up project
cmake_minimum_required(VERSION 3.25.2)
project(DataStructureZoo)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# sources
file(GLOB SOURCES
    structures/*.h
    structures/*.cpp
)

# create executable
add_executable(
    range_sum
    benchmarks/range_sum.cpp
    ${SOURCES}
)

# include directories
include_directories(structures)