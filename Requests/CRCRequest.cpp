#include "CRCRequest.h"

CRCRequest::CRCRequest(std::string clientID, uint8_t version, uint16_t code, std::string fileName)
        : RequestBase(clientID, version, code), fileName(fileName) {
    payloadSize = fileName.size() + 1;
}

std::vector<uint8_t> CRCRequest::buildPayload() const {
    return std::vector<uint8_t>(fileName.begin(), fileName.end());
}