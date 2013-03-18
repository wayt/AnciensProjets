/*
** Sorcerer.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 09:22:52 2013 maxime ginters
** Last update Fri Jan 18 09:22:52 2013 maxime ginters
*/

#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string const& name, std::string const& title) :
    _name(name), _title(title)
{
    std::cout << getName() << ", " << getTitle() << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << getName() << ", " << getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string const& Sorcerer::getName() const
{
    return _name;
}

std::string const& Sorcerer::getTitle() const
{
    return _title;
}

void Sorcerer::polymorph(Victim const& unit) const
{
    unit.getPolymorphed();
}

std::ostream& operator<<(std::ostream& stream, Sorcerer const& unit)
{
    stream << "I am " << unit.getName() << ", " << unit.getTitle() << ", and I like ponies !" << std::endl;
    return stream;
}
