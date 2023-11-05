#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Network/ServerInfo.h"
#include "Network/NetworkManager.h"
#include "Requests/RegistrationRequest.h"

class Client {
private:
    ServerInfo serverInfo;
    std::string clientName;
    std::string filename;
    std::string uniqueID;
    NetworkManager networkManager;
    uint8_t version;

public:
    Client();
    void readTransferInfo();
    void registerWithServer();
    void exchangeKeys();
    void sendEncryptedFile();
    void receiveAndCompareCRC();
    void run();
};

#endif // CLIENT_H