cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(LongNumericArithmetic LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers globally
include_directories(include)

# Collect source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# --- Create a library from your sources ---
add_library(LongNumericArithmeticLib
    ${SOURCES}
)

# Make include directory available to anyone linking this library
target_include_directories(LongNumericArithmeticLib PUBLIC include)

# Apply compiler flags to the library
target_compile_options(LongNumericArithmeticLib PRIVATE
    -Wall
    -Wextra
    -O3
    -funroll-loops
    -march=native
)

# --- Create an executable ---
add_executable(LongNumericArithmeticExe main.cpp)

# Link executable to your library
target_link_libraries(LongNumericArithmeticExe PRIVATE LongNumericArithmeticLib)

