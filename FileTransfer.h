#ifndef FILETRANSFER_H
#define FILETRANSFER_H

#include <string>

class FileTransfer {
public:
    FileTransfer();
    bool sendEncryptedFile(const std::string& filePath);
};

#endif