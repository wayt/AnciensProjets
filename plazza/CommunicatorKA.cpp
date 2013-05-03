/*
 ** CommunicatorKA.cpp for namedPipe in /home/leroy_v/Epitech/projet_tek2/namedPipe
 **
 ** Made by vincent leroy
 ** Login  <leroy_v@epitech.eu>
 **
 ** Started on  Tue Apr 16 16:15:02 2013 vincent leroy
 ** Last update Fri Apr 19 11:10:11 2013 maxime ginters
 */

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include "CommunicatorAK.h"
#include "CommunicatorKA.h"
#include "Log.h"

CommunicatorKA::CommunicatorKA(int id) :
    _pipeName(PIPE_KA_NAME),
    _fdIn(),
    _fdOut()
{
    std::ostringstream oss;
    oss << id;
    _pipeName += oss.str();

    if (mkfifo(_pipeName.c_str(), 0644) == -1 && errno != EEXIST)
        throw std::logic_error("mkfifo \"" + _pipeName + "\" fail: " + strerror(errno));
    if (!_fdIn.open(_pipeName, true))
        throw std::logic_error("open \"" + _pipeName + "\" fail: " + strerror(errno));
    if (!_fdOut.open(PIPE_AK_NAME, false))
        throw std::logic_error("open \"" + std::string(PIPE_AK_NAME) + "\" fail: " + strerror(errno));
}

CommunicatorKA::~CommunicatorKA()
{
    _fdIn.close();
    _fdOut.close();
    unlink(_pipeName.c_str());
}

bool CommunicatorKA::send(const std::string &msg) const
{
    if (!_fdOut.is_open())
    {
        sLog->error("Error: call to KA send with a FIFO not open");
        return (false);
    }

    return _fdOut.send(msg);
}

std::string CommunicatorKA::recv() const
{
    std::string msg;

    if (!_fdIn.is_open())
    {
        sLog->error("Error: call to KA recv with a FIFO not open");
        return "";
    }

    if (!_fdIn.recv(msg))
        throw std::runtime_error(std::string("read fail: ") + strerror(errno));
    return msg;
}

CommunicatorKA const& CommunicatorKA::operator<<(std::string const& msg) const
{
    send(msg);
    return *this;
}

CommunicatorKA const& CommunicatorKA::operator>>(std::string& msg) const
{
    msg = recv();
    return *this;
}
