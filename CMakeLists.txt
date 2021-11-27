cmake_minimum_required(VERSION 3.5)

project(obfuscation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unobfuscated main.cpp)
add_executable(obfuscated main_obfuscated.cpp runner_helpers.h)

