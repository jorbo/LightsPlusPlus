#ifndef LIGHTSPLUSPLUS_LIGHT_H
#define LIGHTSPLUSPLUS_LIGHT_H

#include <stdint-gcc.h>
#include <tuple>
class Light {

public:

    Light(int id);

    bool isOn() const;
    void setOn(bool on);

    uint8_t getBrightness() const;
    void setBrightness(uint8_t brightness);

    uint16_t getHue() const;
    void setHue(uint16_t hue);

    uint8_t getSaturation() const;
    void setSaturation(uint8_t saturation);

    const std::tuple<float, float> &getXyColorspace() const;
    void setXyColorspace(const std::tuple<float, float> &xyColorspace);

    uint16_t getColorTemperature() const;
    void setColorTemperature(uint16_t colorTemperature);

    const std::string &getAlert() const;
    void setAlert(const std::string &alert);

    const std::string &getEffect() const;
    void setEffect(const std::string &effect);

    uint16_t getTransitionTime() const;
    void setTransitionTime(uint16_t transitionTime);

    uint getId() const;

    void setId(uint id);

private:
    bool on;
    uint id;
    uint8_t brightness;
    uint16_t hue;
    uint8_t saturation;
    std::tuple<float, float> xyColorspace;
    uint16_t colorTemperature;
    std::string alert;
    std::string effect;
    uint16_t transitionTime;

};
#endif //LIGHTSPLUSPLUS_LIGHT_H
