cmake_minimum_required(VERSION 3.26)
project(client)


include_directories(/opt/homebrew/Cellar/cryptopp/8.9.0/include)
link_directories(/opt/homebrew/Cellar/cryptopp/8.9.0/lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(client main.cpp
        ClientInstructions.cpp
        ClientInstructions.h
        PublicKeyHandler.cpp
        PublicKeyHandler.h
        AsymmetricEncryption.cpp
        AsymmetricEncryption.h
        SymmetricEncryption.cpp
        SymmetricEncryption.h
        FileTransfer.cpp
        FileTransfer.h
        CommunicationProtocol.cpp
        CommunicationProtocol.h
        client.cpp
        client.h
)
target_link_libraries(client cryptopp)
