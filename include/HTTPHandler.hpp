#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
#include <iostream>
#include "json/json.h"
#ifndef LIGHTSPLUSPLUS_HTTPHANDLER_HPP
#define LIGHTSPLUSPLUS_HTTPHANDLER_HPP

namespace lightspp {

    //! Wrapper class for making cURLpp calls.
    class HTTPHandler {
    public:
        static const Json::Value get(const std::string &route, const bool &withHeader = false);
        static const Json::Value post(const std::string &route, const std::string &messageBody, const bool &withHeader = false);
        static const Json::Value put(const std::string &route, const std::string &messageBody, const bool &withHeader = false);
    private:

    };
}
#endif //LIGHTSPLUSPLUS_HTTPHANDLER_HPP
