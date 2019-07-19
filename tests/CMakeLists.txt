cmake_minimum_required(VERSION 3.14)
project(lights_tests)
add_subdirectory(libs/googletest-release-1.8.1)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(runAllTests main.cpp testing_config.h network_tests.cpp basic_check.cpp)
target_link_libraries(runAllTests lightsplusplus gtest gtest_main)
