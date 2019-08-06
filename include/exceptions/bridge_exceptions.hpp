#ifndef LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
#define LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
namespace lightspp { namespace Exceptions {
    //! Link button exception
    class LinkButtonNotPressed : public runtime_error {
    public:
        //! Exception constructor.
        LinkButtonNotPressed():runtime_error("link button not pressed"){}
        //! \brief return the the text of the error.
         const char *what() const noexcept override {
            return "Link button not pressed";
        }
    };
}}
#endif //LIGHTSPLUSPLUS_BRIDGE_EXCEPTIONS_HPP
