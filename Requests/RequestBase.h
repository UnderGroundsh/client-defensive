#ifndef REQUEST_BASE_H
#define REQUEST_BASE_H

#include <string>
#include <vector>
#include <cstdint>

class RequestBase {
protected:
    const std::string clientID;
    const uint8_t version;
    const uint16_t code;
    uint32_t payloadSize;

    virtual std::vector<uint8_t> buildPayload() const = 0;

public:
    RequestBase(std::string clientID, uint8_t version, uint16_t code);
    std::vector<uint8_t> buildRequest() const;
};

#endif // REQUEST_BASE_H