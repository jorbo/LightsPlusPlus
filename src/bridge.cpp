#include "bridge.h"



Bridge::Bridge(const std::string &address) {
    this->address = address;
}

Bridge::Bridge(const std::string &address, const std::string &port) {
    this->address = address;
    this->port = port;
}

//!
//! \brief Discovers near by bridges via the UPnP strategy
//!
Bridge Bridge::UPnPDiscover() {
    return Bridge();
}

//! Scans all ips from 192.168.1.XXX
Bridge Bridge::IPScan(const std::string &port)
{

    std::string ip;

    // for each ip in range (192.168.1.XXX->255 || 10.10.10.XXX->255 || 172.1...)
    // keep looping till we get a 200 OK from the brige GET


    return Bridge();

}

