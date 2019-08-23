#include "gtest/gtest.h"
#include "bridge.hpp"
#include "group.hpp"

using namespace lightspp;

namespace {
    TEST(group_test, createGroup){
        std::vector<Light> lights;
        lights.emplace_back(Light(2));
        lights.emplace_back(Light(3));
        ASSERT_NO_FATAL_FAILURE(Group::createGroup(lights, "test", "LightGroup", "Room"));
    }
}