/*
** Mage.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d09-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 17 15:53:10 2013 maxime ginters
** Last update Thu Jan 17 15:53:10 2013 maxime ginters
*/

#include <iostream>
#include "Mage.hh"

Mage::Mage(std::string const& name, int level) : Character(name, level, "Mage", "Gnome")
{
    _stats[STAT_STRENGTH] = 6;
    _stats[STAT_STAMINA] = 6;
    _stats[STAT_INTEL] = 12;
    _stats[STAT_SPIRIT] = 11;
    _stats[STAT_AGILITY] = 7;
    std::cout << getName() << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    if (_power < 10)
        return HandleOutOfPower();
    std::cout << getName() << " blinks" << std::endl;
    Range = RANGE;
    _power -= 10;
    return 0;
}

int Mage::RangeAttack()
{
    if (_power < 25)
        return HandleOutOfPower();
    std::cout << getName() << " launches a fire ball" << std::endl;
    _power -= 25;
    return 20 + _stats[STAT_SPIRIT];
}

void Mage::RestorePower()
{
    _power += (50 + _stats[STAT_INTEL]);
    if (_power > 100)
        _power = 100;
    std::cout << getName() << " takes a mana potion" << std::endl;
}
