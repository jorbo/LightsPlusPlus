#ifndef LIGHTSPLUSPLUS_LIGHT_HPP
#define LIGHTSPLUSPLUS_LIGHT_HPP

#include <stdint-gcc.h>
#include <tuple>
#include "bridge.hpp"
#include "json/json.h"
namespace lightspp {
    //! Abstract class representation of a light.
    // TODO: Refactor to not have every function require a bridge as a parameter.
    class Light {

    public:

        Light(int id);

        vector<Light> getAllLights(const Bridge &bridge) const;

        bool isOn(const Bridge &bridge) const;

        Json::Value setOn(const Bridge &bridge, const bool &on);

        uint8_t getBrightness(const Bridge &bridge) const;

        Json::Value setBrightness(const Bridge &bridge, const uint8_t &brightness);

        uint16_t getHue(const Bridge &bridge) const;

        Json::Value setHue(const Bridge &bridge, const uint16_t &hue);

        uint8_t getSaturation(const Bridge &bridge) const;

        Json::Value setSaturation(const Bridge &bridge, const uint8_t &saturation);

        std::tuple<float, float> getXyColorspace(const Bridge &bridge) const;

        Json::Value setXyColorspace(const Bridge &bridge, const std::tuple<float, float> &xyColorspace);

        uint16_t getColorTemperature(const Bridge &bridge) const;

        Json::Value setColorTemperature(const Bridge &bridge, const uint16_t &colorTemperature);

        std::string getAlert(const Bridge &bridge) const;

        Json::Value setAlert(const Bridge &bridge, const std::string &alert);

        std::string getEffect(const Bridge &bridge) const;

        Json::Value setEffect(const Bridge &bridge, const std::string &effect);

        uint16_t getTransitionTime(const Bridge &bridge) const;

        Json::Value setTransitionTime(const Bridge &bridge, const uint16_t &transitionTime);

        uint getId() const;

        void setId(const uint &id);

        std::string getName(const Bridge &bridge);
        Json::Value setName(const Bridge &bridge, const string &name);

    private:
        uint _id;

        Json::Value getState(const Bridge &bridge) const;
        std::string getRoute(const Bridge &bridge) const;

    };
}
#endif //LIGHTSPLUSPLUS_LIGHT_HPP
