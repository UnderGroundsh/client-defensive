#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <boost/asio.hpp>
#include <vector>
#include "ServerInfo.h"

class NetworkManager {
private:
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket;
    ServerInfo serverInfo;

public:

    NetworkManager();
    NetworkManager(ServerInfo serverInfo);
    // Connects to the server
    void connect();
    void setServerInfo(const ServerInfo& info);
    // Sends a request and returns the number of bytes written
    std::size_t sendRequest(const std::vector<uint8_t>& request);

    // Reads a response with a specified size
    std::vector<uint8_t> readResponse(std::size_t size);

    // Closes the connection
    void disconnect();
};

#endif // NETWORK_MANAGER_H