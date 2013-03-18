/*
** Toy.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/jour13/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 10:34:13 2013 maxime ginters
** Last update Mon Jan 21 10:42:46 2013 maxime ginters
*/

#include "Toy.h"

Toy::Toy() :
    _type(BASIC_TOY), _name("toy"), _picture("")
{}

Toy::Toy(ToyType type, std::string const& name, std::string const& filename) :
    _type(type), _name(name), _picture(filename)
{}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string const& Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string const& name)
{
    _name = name;
}

bool Toy::setAscii(std::string const& filename)
{
    return _picture.getPictureFromFile(filename);
}

std::string const& Toy::getAscii() const
{
    return _picture.data;
}
