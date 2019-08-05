#include <string>
#include <exceptions/bridge_exceptions.hpp>
#ifndef LIGHTSPLUSPLUS_BRIDGE_H
#define LIGHTSPLUSPLUS_BRIDGE_H
namespace lightspp {
/*! An abstract class that represents the hue bridge */
    class Bridge {

        public:
            explicit Bridge(const std::string &address);
            static Bridge Discover();
            void setUser(const std::string &userHash);
            std::string getUser() const;
            std::string getAddress() const;
            std::string createUser(const std::string &applicationName, const std::string &username);
            ~Bridge() = default;



    private:
            std::string address = "";
            std::string port = "";
            std::string userHash = "";

            Bridge() = default;





    };
}
#endif //LIGHTSPLUSPLUS_BRIDGE_H
