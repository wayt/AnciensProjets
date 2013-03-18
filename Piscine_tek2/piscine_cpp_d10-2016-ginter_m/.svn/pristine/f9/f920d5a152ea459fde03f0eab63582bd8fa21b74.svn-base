/*
** SuperMutant.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 14:01:25 2013 maxime ginters
** Last update Fri Jan 18 14:01:25 2013 maxime ginters
*/

#include <iostream>
#include "SuperMutant.hh"

SuperMutant::SuperMutant() :
    AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    AEnemy::takeDamage(damage - 3);
}
