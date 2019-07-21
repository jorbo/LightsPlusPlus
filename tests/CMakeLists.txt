cmake_minimum_required(VERSION 3.14)
project(lights_tests)

SET(COVERAGE OFF CACHE BOOL "Coverage")

file(GLOB_RECURSE TEST_FILES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(runAllTests main.cpp ${SOURCE_FILES})
target_link_libraries(runAllTests lightsplusplus gtest gtest_main --coverage)
target_compile_options(runAllTests PRIVATE --coverage -std=c++14 -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
add_subdirectory(libs)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(libs)
include_directories(../include)
