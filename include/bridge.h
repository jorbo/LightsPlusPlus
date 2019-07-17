#include <string>
#ifndef LIGHTSPLUSPLUS_BRIDGE_H
#define LIGHTSPLUSPLUS_BRIDGE_H
/*! An abstract class that represents the hue bridge */
class Bridge {

public:

    static Bridge UPnPDiscover();
    static Bridge IPScan(const std::string &port = "80");


private:
    std::string address = "";
    std::string port = "";


    Bridge() = default;
    ~Bridge() = default;
    explicit Bridge(const std::string &address, const std::string &port = "80");
    explicit Bridge(const std::string &address);




};
#endif //LIGHTSPLUSPLUS_BRIDGE_H
