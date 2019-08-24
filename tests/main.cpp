#include "gtest/gtest.h"
#include "testing_config.h"
#include "lights_test.cpp"
#include "bridge_tests.cpp"
#include "group_tests.cpp"

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}