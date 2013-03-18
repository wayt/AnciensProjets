/*
** Exception.hpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 10:14:13 2013 vincent leroy
** Last update Sat Mar 09 10:50:17 2013 vincent leroy
*/

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <errno.h>
#include <string.h>

namespace Protocol
{

namespace Exception
{

class ExceptSocket : public std::exception
{
    public:
        explicit ExceptSocket() : _msg("Socket error : ") { _msg += strerror(errno); }
        virtual ~ExceptSocket() throw() {}

        const char* what() const throw() { return _msg.c_str(); }

    private:
        std::string _msg;
};

class ExceptConnect : public std::exception
{
    public:
        explicit ExceptConnect(const std::string &ip, int port) : _msg("Connect error : ")
        {
            std::ostringstream oss;
            oss << "ip : " << ip << ", port : " << port << ", " << strerror(errno);
            _msg += oss.str();
        }
        virtual ~ExceptConnect() throw() {}

        const char* what() const throw() { return _msg.c_str(); }

    private:
        std::string _msg;
};

class ExceptSend : public std::exception
{
    public:
        explicit ExceptSend() : _msg() {}
        virtual ~ExceptSend() throw() {}

        const char* what() const throw() { return _msg.c_str(); }

    private:
        std::string _msg;
};

class ExceptRecv : public std::exception
{
    public:
        explicit ExceptRecv() : _msg() {}
        virtual ~ExceptRecv() throw() {}

        const char* what() const throw() { return _msg.c_str(); }

    private:
        std::string _msg;
};

}

}

#endif /* !EXCEPTION_H_ */
