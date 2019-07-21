#include <string>
#ifndef LIGHTSPLUSPLUS_BRIDGE_H
#define LIGHTSPLUSPLUS_BRIDGE_H
namespace lightspp {
/*! An abstract class that represents the hue bridge */
    class Bridge {

        public:

            static Bridge Discover();
            const std::string getAddress() const;
            ~Bridge() = default;



    private:
            std::string address = "";
            std::string port = "";

            Bridge() = default;
            explicit Bridge(const std::string &address);




    };
}
#endif //LIGHTSPLUSPLUS_BRIDGE_H
