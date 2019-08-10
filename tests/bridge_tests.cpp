#include "gtest/gtest.h"
#include "bridge.hpp"

using namespace lightspp;
using namespace lightspp::Exceptions;
namespace {
    TEST(bridge_tests, link_button_not_pressed_test) {
        ASSERT_THROW(bridge.createUser("lightspptest", "test_user"), LinkButtonNotPressed);
    }

}