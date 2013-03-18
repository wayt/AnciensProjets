/*
** TacticalMarine.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 16:59:03 2013 maxime ginters
** Last update Fri Jan 18 16:59:03 2013 maxime ginters
*/

#include <iostream>
#include "TacticalMarine.hh"

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh ..." << std::endl;
}

ISpaceMarine* TacticalMarine::clone() const
{
    return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}
