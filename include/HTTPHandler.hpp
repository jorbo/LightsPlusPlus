#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
#include <json/json.h>
#include <iostream>

#ifndef LIGHTSPLUSPLUS_HTTPHANDLER_HPP
#define LIGHTSPLUSPLUS_HTTPHANDLER_HPP

using namespace curlpp::Options;
namespace lightspp {
/*!
 * This class is a wrapper around the curlpp library
 */
    class HTTPHandler {
    public:
        static const std::string get(const std::string &route);

    private:

    };
}
#endif //LIGHTSPLUSPLUS_HTTPHANDLER_HPP
