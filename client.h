#ifndef CLIENT_H
#define CLIENT_H

#include "ClientInstructions.h"
#include "PublicKeyHandler.h"
#include "AsymmetricEncryption.h"
#include "SymmetricEncryption.h"
#include "FileTransfer.h"
#include "CommunicationProtocol.h"

class Client {
public:
    Client();
    void start();

private:
    ClientInstructions instructions;
    PublicKeyHandler keyHandler;
    AsymmetricEncryption asymEncryption;
    SymmetricEncryption symEncryption;
    FileTransfer fileTransfer;
    CommunicationProtocol commProtocol;
};

#endif
