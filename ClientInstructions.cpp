#include "ClientInstructions.h"
#include <fstream>
#include <string>

ClientInstructions::ClientInstructions() {
    // Constructor logic here
}

bool ClientInstructions::readTransferInfo() {
    std::ifstream file("transfer.info");
    if (!file.is_open()) {
        return false;
    }

    std::getline(file, ipAddress);
    std::getline(file, clientName);
    std::getline(file, filePath);

    file.close();
    return true;
}

std::string ClientInstructions::getIPAddress() {
    return ipAddress;
}

std::string ClientInstructions::getClientName() {
    return clientName;
}

std::string ClientInstructions::getFilePath() {
    return filePath;
}
