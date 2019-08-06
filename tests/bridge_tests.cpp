#include "gtest/gtest.h"
#include "bridge.hpp"

using namespace lightspp;
using namespace lightspp::Exceptions;
namespace {
    TEST(bridge_tests, link_button_not_pressed_test) {
        Bridge bridge = Bridge::Discover();
        ASSERT_THROW(bridge.createUser("lightspptest", "test_user"), LinkButtonNotPressed);
    }

    TEST(bridge_tests, link_button_is_pressed_test) {
        Bridge bridge = Bridge::Discover();
        ASSERT_NO_THROW(bridge.createUser("lightspptest", "test_user"));
    }

}