/*
** Utils.hpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 14:14:28 2013 maxime ginters
** Last update Tue Apr 16 19:14:26 2013 maxime ginters
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <sstream>
#include <vector>
#include "SharedDefines.h"

template<class T>
T to(char const* buff)
{
    T val;
    std::stringstream ss;
    ss << buff;
    ss >> val;
    return val;
}

void split(std::string const& s, char c, std::vector<std::string> &elems);
inline std::string &trim(std::string &s);

uint64 GetMSTime();
uint32 GetMSTimeDiffToNow(uint64 prev);

#endif /* !UTILS_H_ */
