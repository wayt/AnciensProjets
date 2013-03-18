/*
** IMAP.cpp for bmail in /home/vaga/Projects/tek2/bmail
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Mar 09 10:05:04 2013 fabien casters
** Last update Sun Mar 10 11:03:05 2013 vincent leroy
*/

#include "ASocket.h"
#include "Exception.hpp"

namespace Protocol
{

ASocket::ASocket() : _socket(-1)
{
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw Exception::ExceptSocket();
}

ASocket::~ASocket()
{
    if (_socket != -1)
        close(_socket);
}

const std::string ASocket::sendAndReceive(const std::string &cmd) const
{
    if (send(_socket, cmd.c_str(), cmd.length(), 0) == -1)
        throw Exception::ExceptSend();

    char buffer[4096];
    int size;
    std::string result = "";
    usleep(500000);
    do
    {
        if((size = recv(_socket, buffer, 4095, MSG_DONTWAIT)) > 0)
        {
            buffer[size] = '\0';
            result += buffer;
        }
    }
    while (size > 0);

    if (result.length() == 0)
        throw Exception::ExceptRecv();

    return result;
}

void ASocket::connect(const std::string &addr, int port)
{
    struct sockaddr_in sin;
    sin.sin_addr.s_addr = inet_addr(addr.c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    if (::connect(_socket, (struct sockaddr*)&sin, sizeof(sin)) < 0 )
        throw Exception::ExceptConnect(addr, port);

    char buffer[4096];
    int size;
    usleep(500000);
    if((size = recv(_socket, buffer, 4095, MSG_DONTWAIT)) != -1)
    {
        buffer[size] = '\0';
        std::cout << buffer << std::endl;
    }
}

void ASocket::reconnect(const std::string &addr, int port)
{
    if (_socket != -1)
        close(_socket);
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw Exception::ExceptSocket();
    connect(addr, port);
}

}
