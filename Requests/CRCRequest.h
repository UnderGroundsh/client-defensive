#ifndef CRC_REQUEST_H
#define CRC_REQUEST_H

#include "RequestBase.h"

class CRCRequest : public RequestBase {
    std::string fileName;

protected:
    std::vector<uint8_t> buildPayload() const override;

public:
    CRCRequest(std::string clientID, uint8_t version, uint16_t code, std::string fileName);
};

#endif // CRC_REQUEST_H