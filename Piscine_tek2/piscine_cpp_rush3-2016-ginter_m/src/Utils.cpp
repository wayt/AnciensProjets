/*
** Utils.cpp for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 14:50:34 2013 maxime ginters
** Last update Tue Jan 29 21:48:53 2013 fabien casters
*/

#include "Utils.h"

int to_int(const char* str)
{
    std::stringstream ss;
    ss << str;
    int val;
    ss >> val;
    return val;
}

