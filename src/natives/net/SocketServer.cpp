//
// Created by napbad on 10/21/24.
//

#include "SocketServer.h"

#include <cstring>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#endif

SocketServer::SocketServer(const int port) : serverSocket(-1), port(port), running(false) {
    // Initialize Winsock on Windows
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("Failed to initialize Winsock");
    }
#endif
}

SocketServer::~SocketServer() {
    stop();
    // Clean up Winsock on Windows
#ifdef _WIN32
    WSACleanup();
#endif
}

void SocketServer::start() {
    if (running) {
        std::cerr << "Server is already running." << std::endl;
        return;
    }

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        throw std::runtime_error("Failed to create socket");
    }

    // Set the server address
    sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    // Bind the socket
    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0) {
        closeSocket(serverSocket);
        throw std::runtime_error("Bind failed");
    }

    // Listen for connections
    if (listen(serverSocket, 5) < 0) {
        closeSocket(serverSocket);
        throw std::runtime_error("Listen failed");
    }

    running = true;
    std::thread serverThread(&SocketServer::handleClients, this);
    serverThread.detach();
}

void SocketServer::stop() {
    if (!running) {
        return;
    }

    running = false;

    // Close all client connections
    for (auto& thread : clientThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // Close the server socket
    if (serverSocket != -1) {
        closeSocket(serverSocket);
        serverSocket = -1;
    }
}

void SocketServer::handleClient(int clientSocket) const {
    constexpr size_t bufferSize = 1024;
    char buffer[bufferSize];

    while (running) {
        ssize_t bytesReceived = recv(clientSocket, buffer, bufferSize - 1, 0);
        if (bytesReceived <= 0) {
            break; // Client disconnected or receive failed
        }

        buffer[bytesReceived] = '\0';
        std::string message(buffer);
        std::cout << "Received from client: " << message << std::endl;

        // Respond to the client
        std::string response = "Server received: " + message;
        send(clientSocket, response.c_str(), response.size(), 0);
    }

    closeSocket(clientSocket);
}

void SocketServer::handleClients() {
    while (running) {
        sockaddr_in clientAddr{};
        socklen_t addrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        std::cout << "New connection from " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;

        std::thread clientThread(&SocketServer::handleClient, this, clientSocket);
        clientThread.detach();
        clientThreads.push_back(std::move(clientThread));
    }
}

