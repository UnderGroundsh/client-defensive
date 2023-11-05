#include "KeyRequest.h"

KeyRequest::KeyRequest(std::string clientID, uint8_t version, std::string name, std::string publicKey)
        : RequestBase(clientID, version, 1026), name(name), publicKey(publicKey) {
    payloadSize = name.size() + 1 + 160;
}

std::vector<uint8_t> KeyRequest::buildPayload() const {
    std::vector<uint8_t> payload(name.begin(), name.end());
    payload.insert(payload.end(), publicKey.begin(), publicKey.end());
    return payload;
}