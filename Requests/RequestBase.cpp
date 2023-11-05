#include "RequestBase.h"
RequestBase::RequestBase(std::string clientID, uint8_t version, uint16_t code)
        : clientID(clientID), version(version), code(code), payloadSize(0) {}

        std::vector<uint8_t> RequestBase::buildRequest() const {
        std::vector<uint8_t> request;

        // Add header
        request.insert(request.end(), clientID.begin(), clientID.end());
        request.push_back(version);
        request.push_back(code & 0xFF);               // lower byte of code
        request.push_back((code >> 8) & 0xFF);        // upper byte of code
        request.push_back(payloadSize & 0xFF);
        request.push_back((payloadSize >> 8) & 0xFF);
        request.push_back((payloadSize >> 16) & 0xFF);
        request.push_back((payloadSize >> 24) & 0xFF);

        // Add payload
        auto payload = buildPayload();
        request.insert(request.end(), payload.begin(), payload.end());

        return request;
    }
