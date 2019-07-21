#include "gtest/gtest.h"
#include "testing_config.h"
#include "HTTPHandler.hpp"
#include "bridge.hpp"
#include "json/json.h"
#include <string>
namespace {
    using namespace lightspp;

    TEST(network_tests, get_test) {
        Json::Value root = HTTPHandler::get("192.168.1.13/api");
        std::stringstream stream;
        stream << root;
        ASSERT_FALSE(stream.str().length() == 0);
    }

    TEST(network_tests, put_test) {
        auto body = std::string(R"({"on":false})");
        Json::Value root = HTTPHandler::put("192.168.1.13/api/B-Kbd86hucefXclF162UBF9sEx8DgXMsR8TMaznC/lights/7/state",
                                        body);
        std::stringstream stream;
        stream << root;

        ASSERT_FALSE(stream.str().length() == 0);
    }
    TEST(network_tests, post_test){
        Json::Value root;
        auto body = std::string(R"({"devicetype":"testuser"})");
        root = HTTPHandler::post("192.168.1.13/api", body);
        std::ostringstream stream;
        stream << root;
        ASSERT_FALSE(stream.str().length() == 0);

    }

    TEST(network_tests, can_find_bridge){
        auto bridge = Bridge::Discover();
        ASSERT_TRUE(bridge.getAddress() == "192.168.1.13");
    }
}