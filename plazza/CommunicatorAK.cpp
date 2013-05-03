/*
 ** CommunicatorAK.cpp for namedPipe in /home/leroy_v/Epitech/projet_tek2/namedPipe
 **
 ** Made by vincent leroy
 ** Login  <leroy_v@epitech.eu>
 **
 ** Started on  Tue Apr 16 18:21:32 2013 vincent leroy
 ** Last update Wed Apr 17 16:08:02 2013 maxime ginters
 */

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "CommunicatorAK.h"
#include "Log.h"

CommunicatorAK::CommunicatorAK() :
    _fdIn(),
    _fdOut()
{
}

CommunicatorAK::~CommunicatorAK()
{
    std::for_each(_fdOut.begin(), _fdOut.end(), &CommunicatorAK::delFdOut);
    _fdOut.clear();
    _fdIn.close();
    unlink(PIPE_AK_NAME);
}

void CommunicatorAK::init()
{
    if (mkfifo(PIPE_AK_NAME, 0644) == -1 && errno != EEXIST)
        throw std::logic_error("mkfifo \"" + std::string(PIPE_AK_NAME) + "\" fail: " + strerror(errno));
    if (!_fdIn.open(PIPE_AK_NAME, true))
        throw std::logic_error("open \"" + std::string(PIPE_AK_NAME) + "\" fail: " + strerror(errno));
}

void CommunicatorAK::addKitchen(uint32 id)
{
    std::string pipeName;
    std::ostringstream oss;
    oss << id;
    pipeName = PIPE_KA_NAME + oss.str();

    while (!_fdOut[id].open(pipeName, false))
        usleep(50000);
}

void CommunicatorAK::removeKitchen(uint32 id)
{
    std::map<uint32, Stream>::iterator it = _fdOut.find(id);
    if (it == _fdOut.end())
        return ;
    it->second.close();
    _fdOut.erase(it);
}

bool CommunicatorAK::send(const std::string &msg, uint32 id) const
{
    std::map<uint32, Stream>::const_iterator it = _fdOut.find(id);
    if (it == _fdOut.end() || !it->second.is_open())
    {
        sLog->error("Error: call to AK send with an invalide id or FIFO not open");
        return false;
    }
    return it->second.send(msg);
}

std::string CommunicatorAK::recv() const
{
    std::string msg;

    if (!_fdIn.is_open())
    {
        sLog->error("Error: call to AK recv with a FIFO not open");
        return "";
    }

    if (!_fdIn.recv(msg))
        throw std::runtime_error(std::string("read fail: ") + strerror(errno));
    return msg;
}

void CommunicatorAK::delFdOut(std::pair<const uint32, Stream>& p)
{
    if (!p.second.is_open())
        return ;

    std::stringstream ss;

    p.second.close();
    ss << PIPE_KA_NAME << p.first;
    unlink(ss.str().c_str());
}
Stream const& CommunicatorAK::operator[](uint32 id) const
{
    std::map<uint32, Stream>::const_iterator itr = _fdOut.find(id);
    if (itr == _fdOut.end())
        throw std::runtime_error("invalide _fdOut[]");
    return itr->second;
}

CommunicatorAK const& CommunicatorAK::operator>>(std::string &msg)  const
{
    msg = recv();
    return *this;
}
