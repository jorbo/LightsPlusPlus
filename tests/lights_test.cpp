#include "gtest/gtest.h"
#include "HTTPHandler.hpp"
#include "light.hpp"
#include "bridge.hpp"
#include <tuple>
#include <cmath>
using namespace lightspp;

namespace {

    TEST(lights_test, isOn){
        ASSERT_TRUE(light.isOn(bridge));
    }

    TEST(lights_test, setOn){
        ASSERT_FALSE(light.setOn(bridge, true)[0].isMember("error"));
    }

    TEST(lights_test, getBrightness){
        ASSERT_EQ(light.getBrightness(bridge), 254);
    }

    TEST(lights_test, setBrightness){
        ASSERT_FALSE(light.setBrightness(bridge, 254)[0].isMember("error"));

    }

    TEST(lights_test, getHue){
        ASSERT_EQ(light.getHue(bridge), 46403);
    }

    TEST(lights_test, setHue){
        ASSERT_FALSE(light.setHue(bridge, 46406)[0].isMember("error"));
    }

    TEST(lights_test, getSaturation){
        ASSERT_EQ(light.getSaturation(bridge), 242);
    }

    TEST(lights_test, setSaturation){
        ASSERT_FALSE(light.setSaturation(bridge, 242)[0].isMember("error"));
    }

    TEST(lights_test, getXyColorSpace){
        std::tuple<float, float> xy = light.getXyColorspace(bridge);
        float x = std::get<0>(xy);
        float y = std::get<1>(xy);
        ASSERT_TRUE(x == 0.1644f && y == 0.0834f);
    }

    TEST(lights_test, setXyColorSpace){
        std::tuple<float, float> xy = std::make_tuple(0.1644, 0.0833);
        ASSERT_FALSE(light.setXyColorspace(bridge, xy)[0].isMember("error"));
    }

    TEST(lights_test, getAlert){
        ASSERT_EQ(light.getAlert(bridge), "select");
    }

    TEST(lights_test, setAlert){
        ASSERT_FALSE(light.setAlert(bridge, "select")[0].isMember("error"));
    }

    TEST(lights_test, getEffect){
        ASSERT_EQ(light.getEffect(bridge), "none");
    }

    TEST(lights_test, setEffect){
        ASSERT_FALSE(light.setEffect(bridge, "none")[0].isMember("error"));
    }

    TEST(lights_test, getName){
        ASSERT_EQ(light.getName(bridge), "front");
    }

    TEST(lights_test, setName){
        ASSERT_FALSE(light.setName(bridge, "front")[0].isMember("error"));
    }



}