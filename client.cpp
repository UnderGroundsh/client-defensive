#include "Client.h"
#include <iostream>

Client::Client() {

}

void Client::start() {
    // Get instructions from the user
    if (!instructions.readTransferInfo()) {
        std::cerr << "Failed to read transfer information." << std::endl;
        return;
    }

    // Generate and handle RSA keys
    if (!keyHandler.generateRSAKeys()) {
        std::cerr << "Failed to generate RSA keys." << std::endl;
        return;
    }

    if (!keyHandler.savePrivateKey()) {
        std::cerr << "Failed to save the private key." << std::endl;
        return;
    }

    if (!keyHandler.sendPublicKeyToServer()) {
        std::cerr << "Failed to send public key to the server." << std::endl;
        return;
    }

    // Some communication with the server
    if (!commProtocol.sendRequest(100)) { // Example request code
        std::cerr << "Failed to send request." << std::endl;
        return;
    }

    int response = commProtocol.receiveResponse();
    if (response != 200) { // Example success response code
        std::cerr << "Received an error response from the server: " << response << std::endl;
        return;
    }

    // Send encrypted file
    if (!fileTransfer.sendEncryptedFile(instructions.getFilePath())) {
        std::cerr << "Failed to send encrypted file." << std::endl;
        return;
    }

    std::cout << "File transfer successful!" << std::endl;
}
