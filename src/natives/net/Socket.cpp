#include "Socket.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

Socket::Socket() : sockfd(-1) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
}

Socket::~Socket() {
    close(sockfd);
}

void Socket::connect(const std::string& ip, int port) {
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);

    if (::connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

void Socket::send(const std::string& data) {
    if (::send(sockfd, data.c_str(), data.size(), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
}

std::string Socket::receive(size_t bufferSize) {
    char buffer[bufferSize];
    ssize_t bytesReceived = ::recv(sockfd, buffer, bufferSize - 1, 0);
    if (bytesReceived < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Received  "<< bytesReceived <<"bytes: " << buffer << std::endl << std::flush;
    buffer[bytesReceived] = '\0'; // null-terminate the string
    return std::string(buffer);
}
