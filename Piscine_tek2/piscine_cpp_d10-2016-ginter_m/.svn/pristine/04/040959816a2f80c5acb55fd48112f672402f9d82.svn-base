/*
** Ice.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:38:06 2013 maxime ginters
** Last update Sat Jan 19 00:38:06 2013 maxime ginters
*/

#include <iostream>
#include "Ice.hh"

Ice::Ice() :
    AMateria("ice")
{
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
