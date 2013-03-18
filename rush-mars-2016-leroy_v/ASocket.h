/*
** ASocket.h for bmail in /home/vaga/Projects/tek2/bmail
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Mar 09 10:01:40 2013 fabien casters
** Last update Sun Mar 10 06:52:18 2013 vincent leroy
*/

#ifndef SOCKET_H_
# define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

namespace Protocol
{

class ASocket
{
    public:
        ASocket();
        virtual ~ASocket();

        const std::string sendAndReceive(const std::string &) const;
        void connect(const std::string &, int);
        void reconnect(const std::string &, int);
        virtual bool login(const std::string &, const std::string &) const = 0;

    protected:
        int _socket;
};

}

#endif

