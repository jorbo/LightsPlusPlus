#ifndef LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_H
#define LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_H
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
namespace lightspp { namespace Exceptions {
    //! Link button exception
    class InvalidLightID : public runtime_error {
    public:
        //! Exception constructor.
        InvalidLightID():runtime_error("Invalid light id, light does not exist"){}
        //! \brief return the the text of the error.
        const char *what() const noexcept override {
            return "Invalid light id, light does not exist";
        }
    };
}}
#endif //LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_H
