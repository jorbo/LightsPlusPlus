#include "HTTPHandler.hpp"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
#include <sstream>
#include <curlpp/cURLpp.hpp>

using namespace lightspp;


const std::string HTTPHandler::get(const std::string &route){
    try {
        cURLpp::Easy easyHandle;
        cURLpp::Cleanup cleanup;
        std::stringstream result;
        easyHandle.setOpt(cURLpp::Options::Url(route));
        easyHandle.setOpt(cURLpp::Options::Header(1));
        easyHandle.perform();

        return result.str();
    }
    catch(cURLpp::LogicError &e){
        return e.what();
    }
    catch(cURLpp::RuntimeError &e){
        return e.what();
    }


}