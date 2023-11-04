#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

class CommunicationProtocol {
public:
    CommunicationProtocol();
    bool sendRequest(int requestCode);
    int receiveResponse();
};

#endif