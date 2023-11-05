#include "NetworkManager.h"

#include <utility>

NetworkManager::NetworkManager() : socket(io_context) {}


NetworkManager::NetworkManager(ServerInfo  info)
        : socket(io_context), serverInfo(std::move(info)) {}

void NetworkManager::setServerInfo(const ServerInfo& info) {
    serverInfo = info;
}

void NetworkManager::connect() {
    boost::asio::ip::tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(serverInfo.getAddress(), std::to_string(serverInfo.getPort()));
    boost::asio::connect(socket, endpoints);
}

std::size_t NetworkManager::sendRequest(const std::vector<uint8_t>& request) {
    return boost::asio::write(socket, boost::asio::buffer(request, request.size()));
}

std::vector<uint8_t> NetworkManager::readResponse(std::size_t size) {
    std::vector<uint8_t> response(size);
    boost::asio::read(socket, boost::asio::buffer(response, size));
    return response;
}

void NetworkManager::disconnect() {
    socket.close();
}


