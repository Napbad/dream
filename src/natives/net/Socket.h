#ifndef SOCKET_H
#define SOCKET_H

#include <string>

class Socket {
public:
    Socket();
    ~Socket();

    void connect(const std::string& ip, int port);
    void send(const std::string& data);
    std::string receive(size_t bufferSize = 1024);

private:
    int sockfd;
};

#endif // SOCKET_H
