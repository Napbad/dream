#ifndef SOCKET_H
#define SOCKET_H

#include "../../runtime/class/Object.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Socket : public Object
{
    struct
    {
        int sockfd; // File descriptor for the Socket
    } _data{};

    struct
    {
        bool (Socket::*_connect)(const char*, int);
        long int (Socket::*_send)(const void*, unsigned long, int) const;
        long int (Socket::*_receive)(void*, unsigned long, int) const;
        void (Socket::*_closeSocket)();
    } _funcs{};

public:
    Socket();
    ~Socket();

    bool connect(const char* serverIP, int port);
    ssize_t send(const void* buf, size_t len, int flags) const;
    ssize_t receive(void* buf, size_t len, int flags) const;
    void closeSocket();

private:
    bool connectImpl(const char* serverIP, int port);
    ssize_t sendImpl(const void* buf, const size_t len, const int flags) const;
    ssize_t receiveImpl(void* buf, const size_t len, const int flags) const;
    void closeSocketImpl();
};

#endif // SOCKET_H
