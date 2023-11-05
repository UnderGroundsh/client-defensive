#ifndef RECONNECT_REQUEST_H
#define RECONNECT_REQUEST_H

#include "RequestBase.h"

class ReconnectRequest : public RequestBase {
    std::string name;

protected:
    std::vector<uint8_t> buildPayload() const override;

public:
    ReconnectRequest(std::string clientID, uint8_t version, std::string name);
};

#endif // RECONNECT_REQUEST_H