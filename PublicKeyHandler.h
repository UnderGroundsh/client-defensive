#ifndef PUBLICKEYHANDLER_H
#define PUBLICKEYHANDLER_H

class PublicKeyHandler {
public:
    PublicKeyHandler();
    bool generateRSAKeys();
    bool savePrivateKey();
    bool sendPublicKeyToServer();
};

#endif

