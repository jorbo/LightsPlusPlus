//
// Created by jordan on 8/12/19.
//

#include "json/json.h"
#include "HTTPHandler.hpp"
#include "light.hpp"
#include "bridge.hpp"
#ifndef LIGHTSPLUSPLUS_GROUP_H
#define LIGHTSPLUSPLUS_GROUP_H
namespace lightspp {

    class Group {
    public:
        static const std::string roomTypeList[39];
        static const std::string classList[3];

        Group() = default;

        Group(const std::vector<Light> &lights, const std::string &name,
              const std::string &classType = "LightGroup", const std::string &roomType = "Other");

        explicit Group(const int &id);

        static std::vector<Group> getAllGroups();

        static Group createGroup(const std::vector<Light> &lights, const std::string &name,
                                 const std::string &type = "LightGroup",
                                 const std::string &roomType = "Other");

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

        uint getId() const;

        std::string getName() const;

        Json::Value setName(const string &name);

    private:

        int _id;

        void setId(uint id);

        Json::Value getState() const;
        std::string getRoute() const;

        template<class T>
        Json::Value setAttribute(const std::string &attr, const T &value);
        Json::Value setAttribute(const std::tuple<float, float> &value);
        Json::Value setAttribute(const std::vector<Light> &lights);

    };
}

#endif //LIGHTSPLUSPLUS_GROUP_H
