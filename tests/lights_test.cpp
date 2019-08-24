#include "gtest/gtest.h"
#include "HTTPHandler.hpp"
#include "light.hpp"
#include "bridge.hpp"
#include <tuple>
#include <cmath>
using namespace lightspp;

namespace {

//    TEST(lights_test, deleteLight){
//        ASSERT_FALSE(light.deleteLight()[0].isMember("error"));
//    }

    TEST(lights_test, setOn){
        std::cout << light.setOn(true)[0] << std::endl;
        ASSERT_FALSE(light.setOn(true)[0].isMember("error"));
    }

    TEST(lights_test, isOn){
        ASSERT_TRUE(light.isOn());
    }

    TEST(lights_test, setBrightness){
        ASSERT_FALSE(light.setBrightness(254)[0].isMember("error"));

    }
    TEST(lights_test, getBrightness){
        ASSERT_EQ(light.getBrightness(), 254);
    }

    TEST(lights_test, setHue){
        ASSERT_FALSE(light.setHue(46406)[0].isMember("error"));
    }

    TEST(lights_test, getHue){
        ASSERT_EQ(light.getHue(), 46406);
    }

    TEST(lights_test, setSaturation){
        ASSERT_FALSE(light.setSaturation(254)[0].isMember("error"));
    }
    TEST(lights_test, getSaturation){
        ASSERT_EQ(light.getSaturation(), 254);
    }

    TEST(lights_test, setXyColorSpace){
        std::tuple<float, float> xy = std::make_tuple(0.1644, 0.0833);
        ASSERT_FALSE(light.setXyColorspace(xy)[0].isMember("error"));
    }

    // TODO: think of a new way to test this
    // his will basically always fail because of floating point comparison
    TEST(lights_test, getXyColorSpace){
        std::tuple<float, float> xy = light.getXyColorspace();
        float x = std::get<0>(xy);
        float y = std::get<1>(xy);
        ASSERT_TRUE(x == 0.1644f && y == 0.0834f);
    }

    TEST(lights_test, setColorTemp){
        ASSERT_FALSE(light.setColorTemperature(153)[0].isMember("error"));
    }

    TEST(lights_test, getColorTemp){
        ASSERT_EQ(light.getColorTemperature(), 153);
    }

    TEST(lights_test, setAlert){
        ASSERT_FALSE(light.setAlert("select")[0].isMember("error"));
    }

    TEST(lights_test, getAlert){
        ASSERT_EQ(light.getAlert(), "select");
    }

    TEST(lights_test, setEffect){
        ASSERT_FALSE(light.setEffect("none")[0].isMember("error"));
    }

    TEST(lights_test, getEffect){
        ASSERT_EQ(light.getEffect(), "none");
    }

    TEST(lights_test, setName){
        ASSERT_FALSE(light.setName("front")[0].isMember("error"));
    }
    TEST(lights_test, getName){
        ASSERT_EQ(light.getName(), "front");
    }

    TEST(lights_test, getNewLights){
        ASSERT_NO_THROW(Light::getNewLights()[0].isMember("error"));
    }
}