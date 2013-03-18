/*
** Double.cpp for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:41:09 2013 maxime ginters
** Last update Fri Feb 22 13:23:03 2013 maxime ginters
*/

#include <sstream>
#include <iostream>
#include "Double.h"

Double::Double(std::string const& value) : AOperand(TYPE_DOUBLE, 5, value)
{
    size_t pos = _value.find(".");
    if (pos != std::string::npos)
    {
        std::string str = _value.substr(pos);
        for (std::string::const_iterator itr = str.begin(); itr != str.end(); ++itr)
        {

        }
    }
    ld64 check = AOperand::toLd64(_value);
    if (check > std::numeric_limits<double>::max() ||
            check < std::numeric_limits<double>::min())
        throw Exception::ExceptOverflow();
    std::stringstream ss;
    ss << check;
    ss >> _value;
}

double Double::toDouble() const
{
    std::stringstream ss;
    double val = 0.0f;
    ss << _value;
    ss >> val;
    return val;
}

