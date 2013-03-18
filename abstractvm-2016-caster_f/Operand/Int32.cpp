/*
** Int32.cpp for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:41:09 2013 maxime ginters
** Last update Tue Feb 19 16:58:39 2013 maxime ginters
*/

#include <sstream>
#include <iostream>
#include "Int32.h"

Int32::Int32(std::string const& value) : AOperand(TYPE_INT32, 3, value)
{
    int64 check = AOperand::toInt64(_value);
    if (check > std::numeric_limits<int32>::max() ||
            check < std::numeric_limits<int32>::min())
        throw Exception::ExceptOverflow();
    std::stringstream ss;
    ss << check;
    ss >> _value;
}

