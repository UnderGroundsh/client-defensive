#include "RegistrationRequest.h"

RegistrationRequest::RegistrationRequest(std::string clientID, uint8_t version, std::string inputName)
        : RequestBase(clientID, version, 1025), name(inputName) {
    // Ensure the member 'name' is padded to 255 bytes
    if (name.size() < 255) {
        name.append(255 - name.size(), '\0');  // padding with zeros
    }

    payloadSize = 255;
}

std::vector<uint8_t> RegistrationRequest::buildPayload() const {
    return std::vector<uint8_t>(name.begin(), name.end());
}