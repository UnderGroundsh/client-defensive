#ifndef FILE_REQUEST_H
#define FILE_REQUEST_H

#include "RequestBase.h"

class FileRequest : public RequestBase {
    uint32_t fileSize;
    std::string fileName;
    std::vector<uint8_t> fileContent;

protected:
    std::vector<uint8_t> buildPayload() const override;

public:
    FileRequest(std::string clientID, uint8_t version, uint32_t fileSize, std::string fileName, std::vector<uint8_t> fileContent);
};

#endif // FILE_REQUEST_H