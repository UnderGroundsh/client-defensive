#include "ReconnectRequest.h"

ReconnectRequest::ReconnectRequest(std::string clientID, uint8_t version, std::string name)
        : RequestBase(clientID, version, 1027), name(name) {
    payloadSize = name.size() + 1;
}

std::vector<uint8_t> ReconnectRequest::buildPayload() const {
    return std::vector<uint8_t>(name.begin(), name.end());
}