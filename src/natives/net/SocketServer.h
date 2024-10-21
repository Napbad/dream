//
// Created by napbad on 10/21/24.
//

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <thread>
#include <vector>

#ifdef _WIN32
#define closeSocket(s) closesocket(s)
#else
#define closeSocket(s) close(s)
#endif


class SocketServer {
public:
    explicit SocketServer(int port);
    ~SocketServer();

    void start();
    void stop();

private:
    void handleClient(int clientSocket) const;

    int serverSocket;
    int port;
    bool running;
    std::vector<std::thread> clientThreads;
    void handleClients();
};

#endif //SOCKETSERVER_H
