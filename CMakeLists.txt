cmake_minimum_required(VERSION 3.20)

project(LeetCodeSolutions)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(data_structures)

# Leetcode
add_executable(1 src/1_decltype.cpp)
add_executable(2 src/2_namespace.cpp)
add_executable(3 src/3_lvalue_rvalue.cpp)
add_executable(4 src/4_forwarding.cpp)
