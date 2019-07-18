#include "gtest/gtest.h"
#include "../testing_config.h"
#include "HTTPHandler.hpp"
namespace {
    using namespace lightspp;
    TEST(network_tests, test_eq) {
    ASSERT_NE(HTTPHandler::get("www.google.com"), "");
    }
}