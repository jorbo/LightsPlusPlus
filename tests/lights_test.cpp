#include "gtest/gtest.h"
#include "HTTPHandler.hpp"
#include "light.hpp"
#include "bridge.hpp"
using namespace lightspp;

namespace {

    TEST(lights_test, is_light_off_test){
        Bridge bridge(TEST_IP_ADDRESS);
        bridge.setUser(TEST_USER_HASH);
        std::cout << bridge.getAddress();
        Light light(2);
        ASSERT_FALSE(light.isOn(bridge));
    }

    TEST(lights_test, is_light_on_test){
        Bridge bridge(TEST_IP_ADDRESS);
        bridge.setUser(TEST_USER_HASH);
        Light light(2);
        ASSERT_TRUE(light.isOn(bridge));
    }

}