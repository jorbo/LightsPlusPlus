#include "gtest/gtest.h"
#include "../testing_config.h"
namespace {
    TEST(network_tests, test_eq) {
    ASSERT_STRCASEEQ("192.168.1.13", TEST_IP_ADDRESS.c_str());
    }
}