#include <string>
#include <bridge.hpp>
#include <light.hpp>
#ifndef LIGHTSPLUSPLUS_CONFIG_H
#define LIGHTSPLUSPLUS_CONFIG_H
using namespace lightspp;
namespace {
    const std::string TEST_IP_ADDRESS = "192.168.1.5";
    const std::string TEST_USER_HASH = "DQUybgMTSgCfGZlcaX3Ec3DtxAh9sBhSLuMhvKHR";
    Bridge bridge(TEST_IP_ADDRESS, TEST_USER_HASH);
    Light light(19);
}

#endif //LIGHTSPLUSPLUS_CONFIG_H
