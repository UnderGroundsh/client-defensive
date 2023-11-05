#include "FileRequest.h"

FileRequest::FileRequest(std::string clientID, uint8_t version, uint32_t fileSize, std::string fileName, std::vector<uint8_t> fileContent)
        : RequestBase(clientID, version, 1028), fileSize(fileSize), fileName(fileName), fileContent(fileContent) {
    payloadSize = 4 + fileName.size() + 1 + fileContent.size();
}

std::vector<uint8_t> FileRequest::buildPayload() const {
    std::vector<uint8_t> payload;
    payload.insert(payload.end(), fileName.begin(), fileName.end());
    payload.insert(payload.end(), fileContent.begin(), fileContent.end());
    return payload;
}