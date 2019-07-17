include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runNetworkTests network_tests.cpp ../testing_config.h)
target_link_libraries(runNetworkTests gtest gtest_main)
target_link_libraries(runNetworkTests lightsplusplus)