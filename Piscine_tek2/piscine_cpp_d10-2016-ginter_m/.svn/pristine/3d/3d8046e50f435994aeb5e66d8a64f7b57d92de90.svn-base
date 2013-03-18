/*
** Victim.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 09:40:43 2013 maxime ginters
** Last update Fri Jan 18 09:40:43 2013 maxime ginters
*/

#include "Victim.hh"

Victim::Victim(std::string const& name) :
    _name(name)
{
    std::cout << "Some random victim called " << getName() << " just popped !" << std::endl;
}
    
Victim::~Victim()
{
    std::cout << "Victim " << getName() << " just died for no apparent reason !" << std::endl;
}

std::string const& Victim::getName() const
{
    return _name;
}
    
void Victim::getPolymorphed() const
{
    std::cout << getName() << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, Victim const& unit)
{
    stream << "I'm " << unit.getName() << " and i like otters !" << std::endl;;
    return stream;
}
