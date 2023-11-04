#ifndef ASYMMETRICENCRYPTION_H
#define ASYMMETRICENCRYPTION_H

#include <string>

class AsymmetricEncryption {
public:
    AsymmetricEncryption();
    std::string encryptWithRSA(const std::string& data);
    std::string decryptWithRSA(const std::string& encryptedData);
};

#endif
