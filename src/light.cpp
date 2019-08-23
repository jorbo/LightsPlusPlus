#include <light.hpp>
#include <string>
#include <tuple>
#include <HTTPHandler.hpp>
#include <algorithm>

using namespace lightspp;

Light::Light(int id) {
    this->_id = id;
}

//! Returns a list of all the lights that the bridge knows about.
std::vector<Light> Light::getAllLights() const {
    std::vector<Light> lights;
    Json::Value response = HTTPHandler::get(Bridge::bridge->get()->getAddress()+"/lights");
    for_each(response.getMemberNames().begin(), response.getMemberNames().end(), [&](const std::string &lightId){
        Light l(std::stoi(lightId));
        lights.push_back(l);
    });
    return lights;
}

bool Light::isOn() const {
    return this->getState()["on"].asBool();
}

Json::Value Light::setOn(const bool &on) {
    return this->setAttribute("on", on);
}

uint8_t Light::getBrightness() const {
    return this->getState()["bri"].asUInt();
}

Json::Value Light::setBrightness(const uint8_t &brightness) {
    return this->setAttribute("bri", brightness);
}

uint16_t Light::getHue() const {
    return this->getState().asLargestUInt();
}

Json::Value Light::setHue(const uint16_t &hue) {
    return this->setAttribute("hue", hue);
}

uint8_t Light::getSaturation() const {
    return this->getState()["sat"].asUInt();;

}

Json::Value Light::setSaturation(const uint8_t &saturation) {
    return this->setAttribute("sat", saturation);
}

std::tuple<float, float> Light::getXyColorspace() const {
    auto response = this->getState()["xy"];
    return std::make_tuple<float, float>(response[0].asFloat(),response[1].asFloat());
}

Json::Value Light::setXyColorspace(const std::tuple<float, float> &xyColorspace) {
    return this->setAttribute(xyColorspace);
}

uint16_t Light::getColorTemperature() const {
    return this->getState()["ct"].asUInt64();
}

Json::Value Light::setColorTemperature(const uint16_t &colorTemperature) {
    return this->setAttribute("ct", colorTemperature);
}

std::string Light::getAlert() const {
    return this->getState()["alert"].asString();
}

Json::Value Light::setAlert(const std::string &alert) {
    return this->setAttribute("alert", alert);
}

std::string Light::getEffect() const {
    return this->getState()["effect"].asString();
}

Json::Value Light::setEffect(const std::string &effect) {
    return this->setAttribute("effect", effect);
}

uint16_t Light::getTransitionTime() const {
    return this->getState()["transitiontime"].asUInt64();
}

Json::Value Light::setTransitionTime(const uint16_t &transitionTime) {
    return this->setAttribute("transitiontime", transitionTime);
}

uint Light::getId() const {
    return this->_id;
}

std::string Light::getName() const {
    return HTTPHandler::get(this->getRoute())["name"].asString();
}

Json::Value Light::setName(const string &name) {
    Json::Value body;
    body["name"] = name;
    Json::StreamWriterBuilder builder;
    return HTTPHandler::put(this->getRoute(), Json::writeString(builder, body));
}

Json::Value Light::getNewLights() {
    return HTTPHandler::post(Bridge::bridge->get()->getAddress() + "lights", "");
}

Json::Value Light::deleteLight() {
    return HTTPHandler::del(this->getRoute());
}

Json::Value Light::getState() const {
    Json::Value response = HTTPHandler::get(this->getRoute());
    return response["state"];
}

std::string Light::getRoute() const {
    return Bridge::bridge->get()->getAddress() + "lights/" + std::to_string(this->getId());
}

template<class T>
Json::Value Light::setAttribute(const std::string &attr, const T &value) {
    Json::Value body;
    body[attr] = value;
    Json::StreamWriterBuilder builder;
    return HTTPHandler::put(this->getRoute() + "/state", Json::writeString(builder, body));

}
//! \brief special function for dealing with updating xy color space
Json::Value Light::setAttribute(const std::tuple<float, float> &value) {
    Json::Value body;
    body["xy"] = Json::Value(Json::arrayValue);
    body["xy"].append(std::get<0>(value));
    body["xy"].append(std::get<1>(value));
    Json::StreamWriterBuilder builder;
    return HTTPHandler::put(this->getRoute() + "/state", Json::writeString(builder, body));
}
