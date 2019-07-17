project(lights_tests)
add_subdirectory(libs/googletest-release-1.8.1)
add_subdirectory(basic_tests)
add_subdirectory(network_tests)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runAllTests main.cpp testing_config.h network_tests/network_tests.cpp)
target_link_libraries(runAllTests gtest gtest_main)
target_link_libraries(runAllTests lightsplusplus)