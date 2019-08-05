#ifndef LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_HPP
#define LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_HPP
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
namespace lightspp {
    class InvalidParameter : public runtime_error {
    public:
        explicit InvalidParameter(const std::string &input):runtime_error("Invalid value for parameter " + input){
            this->_input = input;
        }
        const char *what() const noexcept override {
            return "Invalid value for parameter ";
        }
    private:
        std::string _input;
    };
}
#endif //LIGHTSPLUSPLUS_LIGHT_EXCEPTIONS_HPP
