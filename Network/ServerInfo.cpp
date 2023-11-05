#include "ServerInfo.h"

ServerInfo::ServerInfo() : address("127.0.0.1"), port(8080){}

ServerInfo::ServerInfo(const std::string& info) {
    size_t colonPos = info.find(':');
    if(colonPos != std::string::npos) {
        address = info.substr(0, colonPos);
        port = std::stoi(info.substr(colonPos + 1));
    }
}

std::string ServerInfo::getAddress() const {
    return address;
}

int ServerInfo::getPort() const {
    return port;
}