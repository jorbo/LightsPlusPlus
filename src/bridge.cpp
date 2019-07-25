#include "bridge.hpp"
#include "HTTPHandler.hpp"
using namespace lightspp;

Bridge::Bridge(const std::string &address) {
    this->address = address;
}

//!
//! \brief Discovers near by bridges via the N-UPnP strategy
//! <a href="https://developers.meethue.com/develop/application-design-guidance/hue-bridge-discovery/#n-upnp">see here</a>
//!
Bridge Bridge::Discover() {
    auto result = HTTPHandler::get("https://discovery.meethue.com/");
    std::string ipAddress = result[0]["internalipaddress"].asString();
    auto *bridge = new Bridge(ipAddress);
    return *bridge;

}

//! \brief returns the IPv4 address of the bridge
const std::string Bridge::getAddress() const {
    return this->address;
}
