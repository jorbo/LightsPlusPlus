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

        vector<Light> getAllLights() const;

        bool isOn() const;
        Json::Value setOn(const bool &on);

        uint8_t getBrightness() const;
        Json::Value setBrightness(const uint8_t &brightness);

        uint16_t getHue() const;
        Json::Value setHue(const uint16_t &hue);

        uint8_t getSaturation() const;
        Json::Value setSaturation(const uint8_t &saturation);

        std::tuple<float, float> getXyColorspace() const;
        Json::Value setXyColorspace(const std::tuple<float, float> &xyColorspace);

        uint16_t getColorTemperature() const;
        Json::Value setColorTemperature(const uint16_t &colorTemperature);

        std::string getAlert() const;
        Json::Value setAlert(const std::string &alert);

        std::string getEffect() const;
        Json::Value setEffect(const std::string &effect);

        uint16_t getTransitionTime() const;
        Json::Value setTransitionTime(const uint16_t &transitionTime);

        std::string getName() const;
        Json::Value setName(const string &name);

        uint getId() const;

        Json::Value deleteLight();

        static Json::Value getNewLights();


    private:
        uint _id;

        Json::Value getState() const;
        std::string getRoute() const;

        template<class T>
        Json::Value setAttribute(const std::string &attr, const T &value);
        Json::Value setAttribute(const std::tuple<float, float> &value);

    };
}
#endif //LIGHTSPLUSPLUS_LIGHT_HPP
