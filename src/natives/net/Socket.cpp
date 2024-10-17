#include "Socket.h"

Socket::Socket() : _data{-1}
{
    _funcs._connect = &Socket::connectImpl;
    _funcs._send = &Socket::sendImpl;
    _funcs._receive = &Socket::receiveImpl;
    _funcs._closeSocket = &Socket::closeSocketImpl;
}

Socket::~Socket()
{
    if (_data.sockfd != -1)
    {
        close(_data.sockfd);
    }
}

bool Socket::connectImpl(const char* serverIP, int port)
{
    _data.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (_data.sockfd < 0)
    {
        std::cerr << "Failed to create Socket" << std::endl;
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

ssize_t Socket::sendImpl(const void* buf, const size_t len, const int flags) const
{
    return ::send(_data.sockfd, buf, len, flags);
}

ssize_t Socket::receiveImpl(void* buf, const size_t len, const int flags) const
{
    return recv(_data.sockfd, buf, len, flags);
}

void Socket::closeSocketImpl()
{
    if (_data.sockfd != -1)
    {
        close(_data.sockfd);
        _data.sockfd = -1;
    }
}

bool Socket::connect(const char* serverIP, int port)
{
    return (this->*_funcs._connect)(serverIP, port);
}

ssize_t Socket::send(const void* buf, size_t len, int flags) const
{
    return (this->*_funcs._send)(buf, len, flags);
}

ssize_t Socket::receive(void* buf, size_t len, int flags) const
{
    return (this->*_funcs._receive)(buf, len, flags);
}

void Socket::closeSocket()
{
    (this->*_funcs._closeSocket)();
}
