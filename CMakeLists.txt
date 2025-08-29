cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(LongNumericArithmetic LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Collect source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Create the executable
add_executable(LongNumericArithmetic
    main.cpp
    ${SOURCES}
)
