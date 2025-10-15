cmake_minimum_required(VERSION 3.20)

project(LeetCodeSolutions)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(data_structures)

# Leetcode
add_executable(decltype src/decltype.cpp)
