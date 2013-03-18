/*
** PlasmaRifle.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 12:25:40 2013 maxime ginters
** Last update Fri Jan 18 12:25:40 2013 maxime ginters
*/

#include <iostream>
#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() :
    AWeapon("Plasma Rifle", 5, 21)
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
