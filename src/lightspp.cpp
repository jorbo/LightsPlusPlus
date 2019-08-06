#include "lightspp.hpp"
#include <curlpp/cURLpp.hpp>

using namespace lightspp;

//!\Brief must be called before you use any other functions
// Initializes curlpp and most likely will be for other stuff later
void Intialize() {
    // required by curlpp
    cURLpp::initialize();
}