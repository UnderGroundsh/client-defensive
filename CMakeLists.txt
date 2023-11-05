cmake_minimum_required(VERSION 3.25.2)
project(client-defensive)

set(CMAKE_CXX_STANDARD 17)

add_executable(client-defensive
        main.cpp
        client.cpp
        client.h
        Network/ServerInfo.cpp
        Network/ServerInfo.h
        Requests/RequestBase.cpp
        Requests/RequestBase.h
        Requests/RegistrationRequest.cpp
        Requests/RegistrationRequest.h
        Requests/ReconnectRequest.cpp
        Requests/ReconnectRequest.h
        Requests/FileRequest.cpp
        Requests/FileRequest.h
        Requests/KeyRequest.cpp
        Requests/KeyRequest.h
        Requests/CRCRequest.cpp
        Requests/CRCRequest.h
        Network/NetworkManager.cpp
        Network/NetworkManager.h
        )


find_package(cryptopp CONFIG REQUIRED)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(client-defensive PRIVATE
        ${Boost_LIBRARIES}
        cryptopp::cryptopp
        ws2_32
        wsock32
        )