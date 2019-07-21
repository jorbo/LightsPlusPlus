#include "HTTPHandler.hpp"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <json/json.h>

using namespace lightspp;


const std::string HTTPHandler::get (const std::string &route, const bool &withHeader){
    try {
        cURLpp::Easy easyHandle;
        cURLpp::Cleanup cleanup;
        std::stringstream result;
        easyHandle.setOpt(cURLpp::Options::Url(route));
        easyHandle.setOpt(cURLpp::Options::Header(withHeader));
        easyHandle.setOpt(cURLpp::Options::HttpGet());
        easyHandle.perform();
        result << easyHandle;
        return result.str();
    }
    catch(cURLpp::LogicError &e){
        return e.what();
    }
    catch(cURLpp::RuntimeError &e){
        return e.what();
    }


}