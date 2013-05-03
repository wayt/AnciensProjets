/*
** Stream.cpp for Plazza in /home/leroy_v/github/Plazza
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Fri Apr 19 13:40:08 2013 vincent leroy
** Last update Sat Apr 20 16:00:05 2013 maxime ginters
*/

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include "Stream.h"

Stream::Stream() :
  _fd(0),
  _isOpen(false)
{
}

Stream::~Stream()
{
}

bool Stream::open(const std::string &filename, bool read)
{
  int flags = read ? O_RDONLY | O_NONBLOCK : O_WRONLY;

  _fd = ::open(filename.c_str(), flags);
  _isOpen = _fd > 0;
  return _isOpen;
}

void Stream::close()
{
  if (_isOpen)
    ::close(_fd);
  _isOpen = false;
}

bool Stream::is_open() const
{
  return _isOpen;
}

bool Stream::send(const std::string &msg) const
{
  if (!is_open())
    return false;

  std::stringstream ss;
  ss << msg << std::endl;
  return (write(_fd, ss.str().c_str(), ss.str().length()) >= 0);
}

bool Stream::recv(std::string &msg) const
{
  char buff[4096];
  int res;

  if (!is_open())
    return false;

  if ((res = read(_fd, buff, 4095)) < 0 && errno != EAGAIN)
    return false;
  else if (res <= 0)
    msg.clear();
  else
  {
    buff[res] = '\0';
    if (buff[res - 1] == '\n')
        buff[res - 1] = 0;
    msg = buff;
  }

  return true;
}

Stream const& operator<<(Stream const& stream, const std::string &msg)
{
  stream.send(msg);
  return stream;
}

Stream const& operator>>(Stream const& stream, std::string &msg)
{
  stream.recv(msg);
  return stream;
}
