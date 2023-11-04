
#ifndef CLIENTINSTRUCTIONS_H
#define CLIENTINSTRUCTIONS_H

#include <string>

class ClientInstructions {
public:
    ClientInstructions();
    bool readTransferInfo();
    std::string getIPAddress();
    std::string getClientName();
    std::string getFilePath();

private:
    std::string ipAddress;
    std::string clientName;
    std::string filePath;
};

#endif
