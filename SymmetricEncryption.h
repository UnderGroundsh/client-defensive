#ifndef SYMMETRICENCRYPTION_H
#define SYMMETRICENCRYPTION_H

#include <string>

class SymmetricEncryption {
public:
    SymmetricEncryption();
    std::string encryptWithAES(const std::string& data);
    std::string decryptWithAES(const std::string& encryptedData);
};

#endif
