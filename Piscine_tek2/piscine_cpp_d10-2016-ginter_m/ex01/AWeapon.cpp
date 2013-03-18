/*
** AWeapon.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 11:16:49 2013 maxime ginters
** Last update Fri Jan 18 11:16:49 2013 maxime ginters
*/

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const& name, int apcost, int damage) :
    _apcost(apcost), _damage(damage), _name(name)
{
}

std::string const& AWeapon::getName() const
{
    return _name;
}

int AWeapon::getAPCost() const
{
    return _apcost;
}

int AWeapon::getDamage() const
{
    return _damage;
}
