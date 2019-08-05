#include "gtest/gtest.h"
#include "testing_config.h"
#include "lights_test.cpp"
#include "bridge_tests.cpp"



//#define RUN_NETWORK_TESTS //!< Uncomment this line if you want to run network tests (will break travis)
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}