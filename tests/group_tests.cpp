#include "gtest/gtest.h"
#include "bridge.hpp"
#include "group.hpp"
using namespace lightspp;

namespace {
    Group group;
    TEST(group_test, createGroup){
        std::vector<Light> lights;
        lights.emplace_back(Light(2));
        lights.emplace_back(Light(3));
        group = Group::createGroup(lights, "test", "LightGroup", "Room");
        Group *pgroup = &group;
        ASSERT_FALSE(pgroup == nullptr);
    }
    TEST(group_test, setOn){
        std::cout << group.setOn(true);
        ASSERT_FALSE(1 == 0);
    }

    TEST(group_test, isOn){
        ASSERT_TRUE(group.isOn());
    }

    TEST(group_test, setBrightness){
//        auto response = group.setBrightness(254);
//        std::cout << response << std::endl;

        ASSERT_FALSE(group.setBrightness(254)[0].isMember("error"));

    }
    TEST(group_test, getBrightness){
        ASSERT_EQ(group.getBrightness(), 254);
    }

    TEST(group_test, setHue){
        ASSERT_FALSE(group.setHue(46406)[0].isMember("error"));
    }

    TEST(group_test, getHue){
        ASSERT_EQ(group.getHue(), 46406);
    }

    TEST(group_test, setSaturation){
        ASSERT_FALSE(group.setSaturation(254)[0].isMember("error"));
    }
    TEST(group_test, getSaturation){
        ASSERT_EQ(group.getSaturation(), 254);
    }

    TEST(group_test, setXyColorSpace){
        std::tuple<float, float> xy = std::make_tuple(0.1644, 0.0833);
        ASSERT_FALSE(group.setXyColorspace(xy)[0].isMember("error"));
    }

    // TODO: think of a new way to test this
    // his will basically always fail because of floating point comparison
    TEST(group_test, getXyColorSpace){
        std::tuple<float, float> xy = group.getXyColorspace();
        float x = std::get<0>(xy);
        float y = std::get<1>(xy);
        ASSERT_TRUE(x == 0.1644f && y == 0.0834f);
    }

    TEST(group_test, setColorTemp){
        ASSERT_FALSE(group.setColorTemperature(153)[0].isMember("error"));
    }

    TEST(group_test, getColorTemp){
        ASSERT_EQ(group.getColorTemperature(), 153);
    }

    TEST(group_test, setAlert){
        ASSERT_FALSE(group.setAlert("select")[0].isMember("error"));
    }

    TEST(group_test, getAlert){
        ASSERT_EQ(group.getAlert(), "select");
    }

    TEST(group_test, setEffect){
        ASSERT_FALSE(group.setEffect("none")[0].isMember("error"));
    }

    TEST(group_test, getEffect){
        ASSERT_EQ(group.getEffect(), "none");
    }

    TEST(group_test, setName){
        ASSERT_FALSE(group.setName("front")[0].isMember("error"));
    }
    TEST(group_test, getName){
        ASSERT_EQ(group.getName(), "front");
    }

}