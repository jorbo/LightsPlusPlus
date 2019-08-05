#ifndef LIGHTSPLUSPLUS_LIGHT_HPP
#define LIGHTSPLUSPLUS_LIGHT_HPP

#include <stdint-gcc.h>
#include <tuple>
#include "bridge.hpp"
#include "exceptions/light_exceptions.hpp"
#include "json/json.h"
namespace lightspp {
    //! Abstract class representation of a light.
    // TODO: Refactor to not have every function require a bridge as a parameter.
    class Light {

    public:

        Light(int id);

        static vector<Light> getAllLights(const Bridge &bridge);

        bool isOn(const Bridge &bridge) const;

        void setOn(const Bridge &bridge, const bool &on);

        uint8_t getBrightness(const Bridge &bridge) const;

        void setBrightness(const Bridge &bridge, const uint8_t &brightness);

        uint16_t getHue(const Bridge &bridge) const;

        void setHue(const Bridge &bridge, const uint16_t &hue);

        uint8_t getSaturation(const Bridge &bridge) const;

        void setSaturation(const Bridge &bridge, const uint8_t &saturation);

        std::tuple<float, float> getXyColorspace(const Bridge &bridge) const;

        void setXyColorspace(const Bridge &bridge, const std::tuple<float, float> &xyColorspace);

        uint16_t getColorTemperature(const Bridge &bridge) const;

        void setColorTemperature(const Bridge &bridge, const uint16_t &colorTemperature);

        std::string getAlert(const Bridge &bridge) const;

        void setAlert(const Bridge &bridge, const std::string &alert);

        std::string getEffect(const Bridge &bridge) const;

        void setEffect(const Bridge &bridge, const std::string &effect);

        uint16_t getTransitionTime(const Bridge &bridge) const;

        void setTransitionTime(const Bridge &bridge, const uint16_t &transitionTime);

        uint getId() const;

        void setId(const uint &id);


    private:
        uint _id;

        Json::Value getState(const Bridge &bridge) const;
        std::string getRoute(const Bridge &bridge) const;

    };
}
#endif //LIGHTSPLUSPLUS_LIGHT_HPP
