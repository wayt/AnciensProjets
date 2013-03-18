/*
** Cure.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:48:02 2013 maxime ginters
** Last update Sat Jan 19 00:48:02 2013 maxime ginters
*/

#include <iostream>
#include "Cure.hh"

Cure::Cure() :
    AMateria("cure")
{
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
