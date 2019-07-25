#include <light.h>
#include <string>
#include <tuple>

Light::Light(int id) {
    this->id = id;
}

bool Light::isOn() const {
    return on;
}

void Light::setOn(bool on) {
    this->on = on;
}

uint8_t Light::getBrightness() const {
    return this->brightness;
}

void Light::setBrightness(uint8_t brightness) {
    this->brightness = brightness;
}

uint16_t Light::getHue() const {
    return this->hue;
}

void Light::setHue(uint16_t hue) {
    this->hue = hue;
}

uint8_t Light::getSaturation() const {
    return saturation;
}

void Light::setSaturation(uint8_t saturation) {
    this->hue = saturation;
}

const std::tuple<float, float> &Light::getXyColorspace() const {
    return this->xyColorspace;
}

void Light::setXyColorspace(const std::tuple<float, float> &xyColorspace) {
    this->xyColorspace = xyColorspace;
}

uint16_t Light::getColorTemperature() const {
    return this->colorTemperature;
}

void Light::setColorTemperature(uint16_t colorTemperature) {
    this->colorTemperature = colorTemperature;
}

const std::string &Light::getAlert() const {
    return this->alert;
}

void Light::setAlert(const std::string &alert) {
    this->alert = alert;
}

const std::string &Light::getEffect() const {
    return this->effect;
}

void Light::setEffect(const std::string &effect) {
    this->effect = effect;
}

uint16_t Light::getTransitionTime() const {
    return this->transitionTime;
}

void Light::setTransitionTime(uint16_t transitionTime) {
    this->transitionTime = transitionTime;
}

uint Light::getId() const {
    return this->id;
}

void Light::setId(uint id) {
    this->id = id;
}
