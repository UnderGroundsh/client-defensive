#ifndef SERVER_INFO_H
#define SERVER_INFO_H

#include <string>

class ServerInfo {
private:
    std::string address;
    int port;

public:
    ServerInfo(); // default constructor
    ServerInfo(const std::string& info);

    std::string getAddress() const;
    int getPort() const;
};

#endif // SERVER_INFO_H