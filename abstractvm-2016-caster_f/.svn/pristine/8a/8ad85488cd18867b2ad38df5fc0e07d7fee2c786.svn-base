/*
** Float.cpp for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:41:09 2013 maxime ginters
** Last update Fri Feb 22 13:22:59 2013 maxime ginters
*/

#include <sstream>
#include <iostream>
#include "Float.h"

Float::Float(std::string const& value) : AOperand(TYPE_FLOAT, 4, value)
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
    if (check > std::numeric_limits<float>::max() ||
            check < std::numeric_limits<float>::min())
        throw Exception::ExceptOverflow();
    std::stringstream ss;
    ss << check;
    ss >> _value;
}

float Float::toFloat() const
{
    std::stringstream ss;
    float val = 0.0f;
    ss << _value;
    ss >> val;
    return val;
}

