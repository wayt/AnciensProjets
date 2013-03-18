/*
** Ratatouille.cpp for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 18:46:14 2013 maxime ginters
** Last update Thu Jan 24 21:41:34 2013 maxime ginters
*/

#include "Ratatouille.h"

Ratatouille::Ratatouille() :
    _ss()
{}

Ratatouille::Ratatouille(Ratatouille const& other) :
    _ss()
{
    _ss << other._ss.str();
}

Ratatouille::~Ratatouille()
{}

Ratatouille& Ratatouille::operator=(Ratatouille const& other)
{
    _ss.str(other._ss.str());
    return *this;
}

Ratatouille& Ratatouille::addVegetable(unsigned char c)
{
    _ss << c;
    return *this;
}

Ratatouille& Ratatouille::addCondiment(unsigned int i)
{
    _ss << i;
    return *this;
}

Ratatouille& Ratatouille::addSpice(double d)
{
    _ss << d;
    return *this;
}

Ratatouille& Ratatouille::addSauce(std::string const& s)
{
    _ss << s;
    return *this;
}

std::string Ratatouille::kooc()
{
    std::string str = _ss.str();
    _ss.clear();
    return str;
}
