//
// Created by napbadsen on 24-10-2.
//

#include "../../runtime/class/Object.h"
#ifndef SOCKET_H
#define SOCKET_H
// < INCLUDE BEGIN > //

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
// < INCLUDE BEGIN > //

// < CLASS DEFINE BEGIN > //

class Socket: public Object
{
    struct
    {
        int sockfd; // File descriptor for the socket
    } _data{};

    struct
    {
        bool (Socket::*_connect)(const char*, int);
        long int (Socket::*_send)(const void*, unsigned long, int) const;
        long int (Socket::*_receive)(void*, unsigned long, int) const;
        void (Socket::*_closeSocket)();
    } _funcs{};

public:
    Socket() : _data{-1}
    {
        _funcs._connect = &Socket::connectImpl;
        _funcs._send = &Socket::sendImpl;
        _funcs._receive = &Socket::receiveImpl;
        _funcs._closeSocket = &Socket::closeSocketImpl;
    }

    ~Socket()
    {
        if (_data.sockfd != -1)
        {
            close(_data.sockfd);
        }
    }

private:
    bool connectImpl(const char* serverIP, int port)
    {
        _data.sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (_data.sockfd < 0)
        {
            std::cerr << "Failed to create socket" << std::endl;
            return false;
        }

        sockaddr_in serv_addr{};
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, serverIP, &serv_addr.sin_addr) <= 0)
        {
            std::cerr << "Invalid address/ Address not supported" << std::endl;
            close(_data.sockfd);
            return false;
        }

        if (::connect(_data.sockfd, reinterpret_cast<sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0)
        {
            std::cerr << "Connection Failed" << std::endl;
            close(_data.sockfd);
            return false;
        }

        return true;
    }

    ssize_t sendImpl(const void* buf, const size_t len, const int flags) const
    {
        return ::send(_data.sockfd, buf, len, flags);
    }

    ssize_t receiveImpl(void* buf, const size_t len, const int flags) const
    {
        return recv(_data.sockfd, buf, len, flags);
    }

    void closeSocketImpl()
    {
        if (_data.sockfd != -1)
        {
            close(_data.sockfd);
            _data.sockfd = -1;
        }
    }

public:
    bool connect(const char* serverIP, int port)  
    {  
        return (this->*_funcs._connect)(serverIP, port);  
    }  
  
    ssize_t send(const void* buf, size_t len, int flags) const  
    {  
        return (this->*_funcs._send)(buf, len, flags);  
    }  
  
    ssize_t receive(void* buf, size_t len, int flags) const  
    {  
        return (this->*_funcs._receive)(buf, len, flags);  
    }  
  
    void closeSocket()  
    {  
        (this->*_funcs._closeSocket)();  
    }   
};

// < CLASS DEFINE END > //


#endif //SOCKET_H
