#include "bridge.hpp"
#include "HTTPHandler.hpp"
#include "json.h"
using namespace lightspp;
using namespace lightspp::Exceptions;
//! Constructs a bridge object from the ip address of the bridge.
Bridge::Bridge(const std::string &address) {
    this->_address = address + "/api/";
}
//! Constructs a bridge object from ip address and user hash
Bridge::Bridge(const std::string &address, const std::string &userHash) {
    this->_address = address + "/api/";
    this->_userHash = userHash;

}

//!
//! \brief Discovers near by bridges via the N-UPnP strategy
//! <a href="https://developers.meethue.com/develop/application-design-guidance/hue-bridge-discovery/#n-upnp">see here</a>
//!
Bridge Bridge::Discover() {
    auto result = HTTPHandler::get("https://discovery.meethue.com/");
    std::string ipAddress = result[0]["internalipaddress"].asString();
    Bridge bridge(ipAddress);
    Json::Value body;
    return bridge;

}

//! \brief returns the IPv4 address of the bridge
std::string Bridge::getAddress() const {
    return this->_address + this->_userHash + "/";
}

//! \brief returns the user
std::string Bridge::getUser() const {
    return this->_userHash;
}

//! \brief Creates a new user to make api calls
//! This should only be called one time and the user hash should be saved in your program
//! such as a config.json file.
std::string Bridge::createUser(const std::string &applicationName, const std::string &userName){
    Json::Value body;
    body["devicetype"] = applicationName + "#" + userName;
    Json::Value result = HTTPHandler::post(this->getAddress(), body.toStyledString());
    if(result[0].isMember("error")){
        throw LinkButtonNotPressed();
    }
    else {
        this->_userHash = result[0]["success"]["username"].asString();
    }
    return this->_userHash;
}

//! Set the user hash to make api calls with
void Bridge::setUser(const std::string &userHash) {
    this->_userHash = userHash;
}
