#ifndef KEY_REQUEST_H
#define KEY_REQUEST_H

#include "RequestBase.h"

class KeyRequest : public RequestBase {
    std::string name;
    std::string publicKey;

protected:
    std::vector<uint8_t> buildPayload() const override;

public:
    KeyRequest(std::string clientID, uint8_t version, std::string name, std::string publicKey);
};

#endif