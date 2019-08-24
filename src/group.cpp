//
// Created by jordan on 8/12/19.
//

#include <algorithm>
#include "group.hpp"
using namespace lightspp;

const std::string Group::classList[3] = { "LightGroup", "Entertainment", "Room" };

const std::string Group::roomTypeList[39] =  {
    "Living room", "Kitchen", "Dining", "Bedroom", "Kids bedroom", "Bathroom", "Nursery",
    "Recreation", "Office", "Gym", "Hallway", "Toilet", "Front door", "Garage", "Terrace",
    "Garden", "Driveway", "Carport", "Other", "Home", "Downstairs", "Upstairs", "Top floor",
    "Attic", "Guest room", "Staircase", "Lounge", "Man cave", "Computer", "Studio", "Music",
    "TV", "Reading", "Closet", "Storage", "Laundry room", "Balcony", "Porch", "Barbecue"
};

Group::Group(const std::vector<Light> &lights, const std::string &name, const std::string &classType,
             const std::string &roomType) {
    *this = createGroup(lights, name, classType, roomType);
}

//! \brief This only sets the id used to perform the get/set functions and doesnt not change the actual ID of the group.
Group::Group(const int &id) {
    this->_id = id;
}

std::vector<Group> Group::getAllGroups() {
    std::vector<Group> groups;
    Json::Value response = HTTPHandler::get(Bridge::bridge->get()->getAddress() + "/groups");
    return std::vector<Group>();
}


Group Group::createGroup(const std::vector<Light> &lights, const std::string &name, const std::string &type, const std::string &roomType) {
    Json::Value body;
    body["name"] = name;
    body["type"] = (std::find(std::begin(classList), std::end(classList), type) != std::end(classList)) ? type : "LightGroup";
    if(body["type"].asString() == "Room")
        body["class"] = (std::find(std::begin(roomTypeList), std::end(roomTypeList), roomType) != std::end(roomTypeList)) ? roomType : "Other";
    body["lights"] = Json::Value(Json::arrayValue);

    for_each(lights.begin(), lights.end(), [&](const Light &light){
        body["lights"].append(std::to_string(light.getId()));
    });

    Json::StreamWriterBuilder builder;
    Json::Value response = HTTPHandler::post(Bridge::bridge->get()->getAddress()+"groups", Json::writeString(builder, body));
    std::cout << response << std::endl;
    std::string id = response[0]["success"]["id"].asString();
    auto group = Group(std::stoi(id));
    group.setId(std::stoi(id));
    return group;
}


bool Group::isOn() const {
    Json::Value response = HTTPHandler::get(this->getRoute())["state"];
    return response["all_on"].asBool();
}

Json::Value Group::setOn(const bool &on) {
//    Json::Value body;
//    body["any_on"] = on;
//    Json::StreamWriterBuilder builder;
//    return HTTPHandler::put(this->getRoute()+"/state", Json::writeString(builder, body));
    return this->setAttribute("on", on);
}

uint8_t Group::getBrightness() const {
    return this->getState()["bri"].asUInt();
}

Json::Value Group::setBrightness(const uint8_t &brightness) {
    return this->setAttribute("bri", brightness);
}

uint16_t Group::getHue() const {
    return this->getState().asUInt64();
}

Json::Value Group::setHue(const uint16_t &hue) {
    return this->setAttribute("hue", hue);
}

uint8_t Group::getSaturation() const {
    return this->getState()["sat"].asUInt();;

}

Json::Value Group::setSaturation(const uint8_t &saturation) {
    return this->setAttribute("sat", saturation);
}

std::tuple<float, float> Group::getXyColorspace() const {
    auto response = this->getState()["xy"];
    return std::make_tuple<float, float>(response[0].asFloat(),response[1].asFloat());
}

Json::Value Group::setXyColorspace(const std::tuple<float, float> &xyColorspace) {
    return this->setAttribute(xyColorspace);
}

uint16_t Group::getColorTemperature() const {
    return this->getState()["ct"].asUInt64();
}

Json::Value Group::setColorTemperature(const uint16_t &colorTemperature) {
    return this->setAttribute("ct", colorTemperature);
}

std::string Group::getAlert() const {
    return this->getState()["alert"].asString();
}

Json::Value Group::setAlert(const std::string &alert) {
    return this->setAttribute("alert", alert);
}

std::string Group::getEffect() const {
    return this->getState()["effect"].asString();
}

Json::Value Group::setEffect(const std::string &effect) {
    return this->setAttribute("effect", effect);
}

uint16_t Group::getTransitionTime() const {
    return this->getState()["transitiontime"].asUInt64();
}

Json::Value Group::setTransitionTime(const uint16_t &transitionTime) {
    return this->setAttribute("transitiontime", transitionTime);
}

uint Group::getId() const {
    return this->_id;
}
void Group::setId(uint id) {
    this->_id = id;
}
std::string Group::getName() const {
    return HTTPHandler::get(this->getRoute())["name"].asString();
}

Json::Value Group::setName(const string &name) {
    Json::Value body;
    body["name"] = name;
    Json::StreamWriterBuilder builder;
    return HTTPHandler::put(this->getRoute(), Json::writeString(builder, body));
}

Json::Value Group::getState() const {
    Json::Value response = HTTPHandler::get(this->getRoute());
    return response["action"];
}

std::string Group::getRoute() const {
    return Bridge::bridge->get()->getAddress() + "groups/" + std::to_string(this->getId());
}

template<class T>
Json::Value Group::setAttribute(const std::string &attr, const T &value) {
    Json::Value body;
    body[attr] = value;
    Json::StreamWriterBuilder builder;
    auto response = HTTPHandler::put(this->getRoute()+"/action", Json::writeString(builder, body));
    return response;

}
//! \brief special function for dealing with updating xy color space
Json::Value Group::setAttribute(const std::tuple<float, float> &value) {
    Json::Value body;
    body["xy"] = Json::Value(Json::arrayValue);
    body["xy"].append(std::get<0>(value));
    body["xy"].append(std::get<1>(value));
    Json::StreamWriterBuilder builder;
    std::cout << this->getRoute() << std::endl;
    return HTTPHandler::put(this->getRoute()+"/action", Json::writeString(builder, body));
}

//! \brief special implementation for setting light array
Json::Value Group::setAttribute(const std::vector<Light> &lights) {
    Json::Value body;
    body["lights"] = Json::Value(Json::arrayValue);
    std::for_each(lights.begin(), lights.end(), [&](const Light &light){
       body["lights"].append(light.getId());
    });
    Json::StreamWriterBuilder builder;
    return HTTPHandler::put(this->getRoute()+"/action2", Json::writeString(builder, body));
}

