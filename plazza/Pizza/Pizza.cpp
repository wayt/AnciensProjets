/*
** Pizza.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:07:46 2013 maxime ginters
** Last update Fri Apr 19 13:30:16 2013 maxime ginters
*/

#include <vector>
#include "Utils.hpp"
#include "Pizza.h"

Pizza::Pizza(std::string const& str) : _type(REGINA), _size(S)
{
    std::vector<std::string> elems;
    split(str, ':', elems);
    _type = (TypePizza)to<uint32>(elems[1].c_str());
    _size = (TaillePizza)to<uint32>(elems[2].c_str());
}

Pizza::Pizza(TypePizza type, TaillePizza size) :
    _type(type), _size(size)
{}

TypePizza Pizza::getType() const
{
    return _type;
}

TaillePizza Pizza::getSize() const
{
    return _size;
}

std::ostream& operator<<(std::ostream& stream, Pizza const& pizz)
{
    stream << "PIZZA:" << pizz.getType() << ":" << pizz.getSize();
    return stream;
}

