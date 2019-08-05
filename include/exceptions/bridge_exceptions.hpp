#ifndef LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
#define LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
namespace lightspp {
    class LinkButtonNotPressed : public runtime_error {
    public:
        LinkButtonNotPressed():runtime_error("link button not pressed"){}
         const char *what() const noexcept override {
            return "Link button not pressed";
        }
    };
}
#endif //LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
