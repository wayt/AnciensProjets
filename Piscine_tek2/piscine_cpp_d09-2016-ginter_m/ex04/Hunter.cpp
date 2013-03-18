/*
** Hunter.cpp for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d09-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 17 18:23:16 2013 maxime ginters
** Last update Thu Jan 17 18:23:16 2013 maxime ginters
*/

#include <iostream>
#include "Hunter.hh"

Hunter::Hunter(std::string const& name, int level) : Character(name, level, "Hunter", "Elf"), Warrior(name, level), _weapon("sword")
{
    _stats[STAT_STRENGTH] = 9;
    _stats[STAT_STAMINA] = 9;
    _stats[STAT_INTEL] = 5;
    _stats[STAT_SPIRIT] = 6;
    _stats[STAT_AGILITY] = 24;
    _class = "Hunter";
    _race = "Elf";
    std::cout << getName() << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack()
{
    if (_power < 30)
        return HandleOutOfPower();
    _power -= 30;
    std::cout << getName() << " strikes with his " << _weapon << std::endl;
    return 20 + _stats[STAT_STRENGTH];
}

int Hunter::RangeAttack()
{
    if (_power < 25)
        return HandleOutOfPower();
    _power -= 25;
    std::cout << getName() << " uses his bow" << std::endl;
    return 20 + _stats[STAT_AGILITY];
}

void Hunter::Heal()
{
    _pv += 50;
    if (_pv > 100)
        _pv = 100;
    std::cout << getName() << " takes a potion" << std::endl;
}

void Hunter::RestorePower()
{
    _power = 100;
    std::cout << getName() << " meditates" << std::endl;
}
