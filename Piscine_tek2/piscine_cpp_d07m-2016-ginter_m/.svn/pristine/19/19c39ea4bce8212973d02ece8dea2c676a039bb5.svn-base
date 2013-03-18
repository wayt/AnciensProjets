/*
** Borg.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 11:11:04 2013 maxime ginters
** Last update Tue Jan 15 11:11:04 2013 maxime ginters
*/

#include <iostream>
#include "Borg.hh"

namespace Borg
{

Ship::Ship(int wF, short repair) : _side(300), _maxWarp(9), _core(NULL),
    _home(UNICOMPLEX), _location(UNICOMPLEX),
    _shield(100), _weaponFrequency(wF), _repair(repair)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." <<std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
}

void Ship::checkCore()
{
    if (!_core || !_core->getReactor())
        return;
    std::cout << (_core->getReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp)
        return false;
    if (_location == d)
        return false;
    if (!_core || !_core->getReactor() ||!_core->getReactor()->isStable())
        return false;
    _location = d;
    return true;
}

bool Ship::move(int warp)
{
    if (warp > _maxWarp)
        return false;
    if (_location == _home)
        return false;
    if (!_core || !_core->getReactor() || !_core->getReactor()->isStable())
        return false;
    _location = _home;
    return true;
}

bool Ship::move(Destination d)
{
    if (_location == d)
        return false;
    if (!_core || !_core->getReactor() || !_core->getReactor()->isStable())
        return false;
    _location = d;
    return true;
}

bool Ship::move()
{
    if (_location == _home)
        return false;
    if (!_core || !_core->getReactor() || !_core->getReactor()->isStable())
        return false;
    _location = _home;
    return true;
}

int Ship::getShield()
{
    return _shield;
}

void Ship::setShield(int val)
{
    if (val < 0)
        val = 0;
    _shield = val;
}

int Ship::getWeaponFrequency()
{
    return _weaponFrequency;
}

void Ship::setWeaponFrequency(int val)
{
    if (val < 0)
        val = 0;
    _weaponFrequency = val;
}

short Ship::getRepair()
{
    return _repair;
}

void Ship::setRepair(short val)
{
    _repair = val;
}

void Ship::fire(Federation::Starfleet::Ship* target)
{
    if (!target)
        return;
    target->setShield(target->getShield() - getWeaponFrequency());
    std::cout << "Firing on target with " << getWeaponFrequency() << "GW frequency." << std::endl;
}

void Ship::fire(Federation::Ship* target)
{
    if (!target)
        return;
    if (WarpSystem::Core* core = target->getCore())
        if (core->getReactor())
            core->getReactor()->setStability(false);
    std::cout << "Firing on target with " << getWeaponFrequency() << "GW frequency." << std::endl;
}

void Ship::repair()
{
    if (getRepair() > 0)
    {
        setShield(100);
        setRepair(getRepair() - 1);
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
    else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}


} // !namespace Borg
