/*
** AOperand.cpp for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:00:46 2013 maxime ginters
** Last update Fri Feb 22 13:46:23 2013 maxime ginters
*/

#include <sstream>
#include <algorithm>
#include "AOperand.h"

AOperand::AOperand(eOperandType type, int precision, std::string const& value) :
    _type(type), _precision(precision), _value(value)
{
    std::for_each(_value.begin(), _value.end(), std::bind1st(std::mem_fun(&AOperand::checkNumber), this));
}

std::string const& AOperand::toString() const
{
    return _value;
}

int AOperand::getPrecision() const
{
    return _precision;
}

eOperandType AOperand::getType() const
{
    return _type;
}

int64 AOperand::toInt64(std::string const& str)
{
    int64 v;
    std::stringstream ss;
    ss << str;
    ss >> v;
    return v;
}

ld64 AOperand::toLd64(std::string const& str)
{
    ld64 v;
    std::stringstream ss;
    ss << str;
    ss >> v;
    return v;
}

IOperand* AOperand::operator+(const IOperand &rhs) const
{
    std::stringstream ss;
    ss << (AOperand::toLd64(toString()) + AOperand::toLd64(rhs.toString()));
    return sOperandFactory->createOperand((rhs.getPrecision() > getPrecision() ? rhs.getType() : getType()), ss.str());
}
IOperand* AOperand::operator-(const IOperand &rhs) const
{
    std::stringstream ss;
    ss << (AOperand::toLd64(toString()) - AOperand::toLd64(rhs.toString()));
    return sOperandFactory->createOperand((rhs.getPrecision() > getPrecision() ? rhs.getType() : getType()), ss.str());
}
IOperand* AOperand::operator*(const IOperand &rhs) const
{
    std::stringstream ss;
    ss << (AOperand::toLd64(toString()) * AOperand::toLd64(rhs.toString()));
    return sOperandFactory->createOperand((rhs.getPrecision() > getPrecision() ? rhs.getType() : getType()), ss.str());
}
IOperand* AOperand::operator/(const IOperand &rhs) const
{
    std::stringstream ss;
    ld64 d = AOperand::toLd64(rhs.toString());
    if (d == 0.0)
        throw Exception::ExceptZero();
    ss << (AOperand::toLd64(toString()) / d);
    return sOperandFactory->createOperand((rhs.getPrecision() > getPrecision() ? rhs.getType() : getType()), ss.str());
}
IOperand* AOperand::operator%(const IOperand &rhs) const
{
    if (getType() >= TYPE_FLOAT || rhs.getType() >= TYPE_FLOAT)
        throw Exception::ExceptDecimaleModulo();
    std::stringstream ss;
    int64 d = AOperand::toInt64(rhs.toString());
    if (d == 0)
        throw Exception::ExceptZero();
    ss << (AOperand::toInt64(toString()) % d);
    return sOperandFactory->createOperand((rhs.getPrecision() > getPrecision() ? rhs.getType() : getType()), ss.str());
}

bool AOperand::operator==(const IOperand &rhs) const
{
    return (rhs.getType() == getType() && rhs.toString() == toString());
}

void AOperand::checkNumber(char itr)
{
    if ((itr >= '0' && itr <= '9') || itr == '.')
        return;
    throw Exception::ExceptInvalideNumber();
}

