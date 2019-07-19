#include "lightspp.hpp"
#include <curlpp/cURLpp.hpp>

using namespace lightspp;

void Intialize() {

    // required by curlpp
    cURLpp::initialize();
}