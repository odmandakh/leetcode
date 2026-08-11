cmake_minimum_required(VERSION 4.2)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Makes PROJECT_ROOT available in code so test files resolve regardless of working dir
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

add_executable(LeetCode main.cpp)

# So `#include "runner.h"` resolves from problems/*.cpp too, not just main.cpp
target_include_directories(LeetCode PRIVATE ${CMAKE_SOURCE_DIR})
