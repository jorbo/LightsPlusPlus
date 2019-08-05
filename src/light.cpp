#include <light.hpp>
#include <string>
#include <tuple>
#include <HTTPHandler.hpp>
#include <algorithm>

using namespace lightspp;

Light::Light(int id) {
    this->id = id;
}

//! \brief returns the on/off state of the light
bool Light::isOn(const Bridge &bridge) const {
    return this->getState(bridge)["on"].asBool();
}

//! \brief sets the on/off state of the light
void Light::setOn(const Bridge &bridge, const bool &on) {
    Json::Value body;
    body["on"] = on;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
 }

 //! \brief return the current brightness of the light
uint8_t Light::getBrightness(const Bridge &bridge) const {
    return this->getState(bridge)["bri"].asUInt();
}

//! \brief set the brightness of the light
void Light::setBrightness(const Bridge &bridge, const uint8_t &brightness) {
    Json::Value body;
    body["bri"] = brightness;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current hue of the light
uint16_t Light::getHue(const Bridge &bridge) const {
    return getState(bridge)["hue"].asUInt();
}

//! \brief sets the hue of the light
void Light::setHue(const Bridge &bridge, const uint16_t &hue) {
    Json::Value body;
    body["hue"] = hue;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current saturation level of the light
uint8_t Light::getSaturation(const Bridge &bridge) const {
    return getState(bridge)["sat"].asUInt();
}

//! \brief sets the saturation level of the light
void Light::setSaturation(const Bridge &bridge, const uint8_t &saturation) {
    Json::Value body;
    body["sat"] = saturation;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current x and y color space positions of the light
std::tuple<float, float> Light::getXyColorspace(const Bridge &bridge) const {
    Json::Value state = this->getState(bridge)["xy"];
    return std::make_tuple(state[0].asFloat(), state[1].asFloat());
}

//! \brief sets the current x and y color space positions of the light
void Light::setXyColorspace(const Bridge &bridge, const std::tuple<float, float> &xyColorspace) {
    Json::Value body;
    Json::Value array;
    array.append(std::get<0>(xyColorspace));
    array.append(std::get<1>(xyColorspace));
    body["xy"] = array;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current color temperature of the light
uint16_t Light::getColorTemperature(const Bridge &bridge) const {
    return this->getState(bridge)["ct"].asUInt();
}

//! \brief sets the color temperature of the light
void Light::setColorTemperature(const Bridge &bridge, const uint16_t &colorTemperature) {
    Json::Value body;
    body["ct"] = colorTemperature;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current alert mode of the light
std::string Light::getAlert(const Bridge &bridge) const {
    return this->getState(bridge)["alert"].asString();
}

//! \brief sets the alert mode for the light
void Light::setAlert(const Bridge &bridge, const std::string &alert) {
    Json::Value body;
    body["alert"] = alert;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief get the active effect mode of the light
std::string Light::getEffect(const Bridge &bridge) const {
    return this->getState(bridge)["effect"].asString();
}

//! \brief set the effect mode of the light
void Light::setEffect(const Bridge &bridge, const std::string &effect) {
    Json::Value body;
    body["effect"] = effect;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current transition time for the light
uint16_t Light::getTransitionTime(const Bridge &bridge) const {
    return this->getState(bridge)["transitiontime"].asUInt();
}

//! \brief sets the transition time for the light
void Light::setTransitionTime(const Bridge &bridge, const uint16_t &transitionTime) {
    Json::Value body;
    body["transitiontime"] = transitionTime;
    HTTPHandler::put(this->getRoute(bridge), body.asString());
}

//! \brief gets the current id of the light
uint Light::getId() const {
    return this->id;
}

//! \brief sets the id of the light
void Light::setId(const uint &id) {
    this->_id = id;
}

//! Helper function that constructs the proper url and returns the whole state of the light
Json::Value Light::getState(const Bridge &bridge) const {
    std::string route = bridge.getAddress()+"lights/"+std::to_string(this->getId());
    Json::Value root = HTTPHandler::get(route);
    Json::Value state = root["state"];
    return state;
}

//! Helper function to set form the url to update the light's state
std::string Light::getRoute(const Bridge &bridge) const {
    return bridge.getAddress()+"lights/" + std::to_string(this->getId())+"/state";
}

vector<Light> Light::getAllLights(const Bridge &bridge){
    std::vector<Light> lights;
    Json::Value response = HTTPHandler::get(bridge.getAddress()+"/lights");
    for_each(response.getMemberNames().begin(), response.getMemberNames().end(), [&](std::string *lightId){
        Light l(std::stoi(*lightId));
        lights.push_back(l);
    });
    return lights;
}

