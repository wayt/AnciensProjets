/*
** AMateria.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:21:46 2013 maxime ginters
** Last update Sat Jan 19 00:21:46 2013 maxime ginters
*/

#include "AMateria.hh"
#include "ICharacter.hh"

AMateria::AMateria(std::string const& type) :
    xp_(0), type_(type)
{
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return type_;
}

unsigned int AMateria::getXP() const
{
    return xp_;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    xp_ += 10;
}
