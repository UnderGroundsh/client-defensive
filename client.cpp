#include "Client.h"
#include <cryptopp/rsa.h>
#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/modes.h>
#include <cryptopp/crc.h>


Client::Client()  {
    readTransferInfo();
    networkManager.setServerInfo(serverInfo);
}

void Client::readTransferInfo() {
    std::ifstream file("transfer.info");
    if(file) {
        std::string info;
        std::getline(file, info);
        serverInfo = ServerInfo(info);
        std::getline(file, clientName);
        std::getline(file, filename);
        version = 1;
    } else {
        std::cerr << "Unable to open transfer.info" << std::endl;
        exit(1);
    }
}

void Client::registerWithServer() {
    networkManager.connect();
    std::vector<uint8_t> request;
    RegistrationRequest req = RegistrationRequest("0000000000000000", version,clientName);
    request = req.buildRequest();
    networkManager.sendRequest(request);
    auto response = networkManager.readResponse(21);
    // Process your response here and assign it to uniqueID

    // Save unique ID to me.info
    std::ofstream out("me.info");
    if(out) {
        out << uniqueID;
    } else {
        std::cerr << "Unable to save to me.info" << std::endl;
        exit(1);
    }
    networkManager.disconnect();
}

void Client::exchangeKeys() {
//    CryptoPP::InvertibleRSAFunction params;
//    CryptoPP::RSA::PrivateKey privateKey(params);
//    CryptoPP::RSA::PublicKey publicKey(params);

    // Convert the public key to a string and send
    std::string pubKeyStr;
//    CryptoPP::StringSink ss(pubKeyStr);
//    publicKey.Save(ss);

    networkManager.connect();
    std::vector<uint8_t> request;

    networkManager.sendRequest(request);
    auto response = networkManager.readResponse(2102);
    // Process the response and set the aesKey for later use
    networkManager.disconnect();
}

void Client::sendEncryptedFile() {
    std::string plaintext, ciphertext;
//    CryptoPP::FileSource(filename.c_str(), true, new CryptoPP::StringSink(plaintext));

    // Encrypt with AES
//    CryptoPP::AES::Encryption aesEncryption(aesKey.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
//    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv.data()); // Assuming you have an IV
//    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
//    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.data()), plaintext.size());
//    stfEncryptor.MessageEnd();

    networkManager.connect();
    std::vector<uint8_t> request;
    networkManager.sendRequest(request);
    networkManager.disconnect();
}

void Client::receiveAndCompareCRC() {
    networkManager.connect();
    auto crcFromServer = networkManager.readResponse(2103);

    std::string fileData;
//    CryptoPP::FileSource(filename.c_str(), true, new CryptoPP::StringSink(fileData));
//    CryptoPP::CRC32 crc;
    std::string localCRC;
//    CryptoPP::StringSource(fileData, true, new CryptoPP::HashFilter(crc, new CryptoPP::HexEncoder(new CryptoPP::StringSink(localCRC))));

//    if(localCRC == crcFromServer) {
//        std::cout << "CRC matches!" << std::endl;
//    } else {
//        std::cerr << "CRC mismatch!" << std::endl;
//    }
}

void Client::run() {
    registerWithServer();
    exchangeKeys();
    sendEncryptedFile();
    receiveAndCompareCRC();
    }