#ifndef REGISTRATION_REQUEST_H
#define REGISTRATION_REQUEST_H

#include "RequestBase.h"

class RegistrationRequest : public RequestBase {




    std::string name;

protected:
    std::vector<uint8_t> buildPayload() const override;

public:
    RegistrationRequest(std::string clientID, uint8_t version, std::string inputName);
};

#endif // REGISTRATION_REQUEST_H