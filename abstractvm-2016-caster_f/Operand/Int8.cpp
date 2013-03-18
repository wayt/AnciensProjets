/*
** Int8.cpp for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:41:09 2013 maxime ginters
** Last update Mon Feb 18 19:21:18 2013 maxime ginters
*/

#include <sstream>
#include <iostream>
#include "Int8.h"

Int8::Int8(std::string const& value) : AOperand(TYPE_INT8, 1, value)
{
    int64 check = AOperand::toInt64(_value);
    if (check > std::numeric_limits<int8>::max() ||
            check < std::numeric_limits<int8>::min())
        throw Exception::ExceptOverflow();
    std::stringstream ss;
    ss << check;
    ss >> _value;
}

