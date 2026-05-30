cmake_minimum_required(VERSION 4.2)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)

# Makes PROJECT_ROOT available in code so test files resolve regardless of working dir
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

add_executable(LeetCode main.cpp)
