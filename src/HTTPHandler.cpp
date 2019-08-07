#include "HTTPHandler.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
#include <sstream>

#include <json/json.h>

using namespace lightspp;


//! \brief Performs an http get request
//! \param route url route for the request
//! \param withHeader if you want the http header back
//! \return the response as json
const Json::Value HTTPHandler::get (const std::string &route, const bool &withHeader) {
    try {
        cURLpp::Easy request;
        cURLpp::Cleanup cleanup;
        std::stringstream result;
        std::list<std::string> header;
        header.emplace_back("Content-Type: application/json");
        request.setOpt(new cURLpp::Options::Url(route));
        request.setOpt(new cURLpp::Options::Header(withHeader));
        request.setOpt(new cURLpp::Options::HttpHeader(header));
        request.setOpt(new cURLpp::Options::WriteStream(&result));
        request.perform();
        Json::Value json;
        result >> json;
        return json;
    }
    catch (cURLpp::LogicError &e) {
        return e.what();
    }
    catch (cURLpp::RuntimeError &e) {
        return e.what();
    }

}
//! \brief Performs an http post request
//! \param route url route for the request
//! \param messageBody body to send with request
//! \param withHeader if you want the http header back
//! \return the response as json
const Json::Value HTTPHandler::post(const std::string &route, const std::string &messageBody, const bool &withHeader) {
    try {
        cURLpp::Easy request;
        cURLpp::Cleanup cleanup;
        std::stringstream result;
        std::list<std::string> header;
        header.emplace_back("Content-Type: application/json");
        request.setOpt(new cURLpp::Options::Url(route));
        request.setOpt(new cURLpp::Options::Header(withHeader));
        request.setOpt(new cURLpp::Options::PostFields(messageBody));
        request.setOpt(new cURLpp::Options::PostFieldSize(messageBody.length()));
        request.setOpt(new cURLpp::Options::HttpHeader(header));
        request.setOpt(new cURLpp::Options::WriteStream(&result));
        request.perform();
        Json::Value json;
        result >> json;
        return json;
    }
    catch(cURLpp::LogicError &e){
        return e.what();
    }
    catch(cURLpp::RuntimeError &e){
        return e.what();
    }
}

//! \brief Performs an http put request
//! \param route url route for the request
//! \param messageBody body to send with request
//! \param withHeader if you want the http header back
//! \return the response as json
const Json::Value HTTPHandler::put(const std::string &route, const std::string &messageBody, const bool &withHeader) {
    try {
        cURLpp::Easy request;
        cURLpp::Cleanup cleanup;
        std::stringstream result;
        std::list<std::string> header;
        header.emplace_back("Content-Type: application/json");
        request.setOpt(new cURLpp::Options::Url(route));
        request.setOpt(new cURLpp::Options::Header(withHeader));
        request.setOpt(new cURLpp::Options::CustomRequest{"PUT"});
        request.setOpt(new cURLpp::Options::PostFields(messageBody));
        request.setOpt(new cURLpp::Options::PostFieldSize(messageBody.length()));
        request.setOpt(new cURLpp::Options::HttpHeader(header));
        request.setOpt(new cURLpp::Options::WriteStream(&result));
        request.perform();
        Json::Value json;
        result >> json;
        return json;
    }
    catch(cURLpp::LogicError &e){
        return e.what();
    }
    catch(cURLpp::RuntimeError &e){
        return e.what();
    }
}
