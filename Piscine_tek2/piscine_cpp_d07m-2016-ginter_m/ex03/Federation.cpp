/*
** Federation.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 09:45:39 2013 maxime ginters
** Last update Tue Jan 15 09:45:39 2013 maxime ginters
*/

#include <iostream>
#include "Federation.hh"

namespace Federation
{

namespace Starfleet
{

Ship::Ship() :
    _length(289), _width(132), _name("Entreprise"), _maxWarp(6),
    _core(NULL), _captain(NULL), _home(EARTH), _location(EARTH),
    _shield(100), _photonTorpedo(20)
{
    std::cout << "The ship USS " << _name << " has been finished. It is " << _length << " m in length and " << _width << " m in width." << " It can go to Warp " << _maxWarp << "! " << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;

}

Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(NULL), _captain(NULL), _home(EARTH), _location(EARTH),
    _shield(100), _photonTorpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished. It is " << _length << " m in length and " << _width << " m in width." << " It can go to Warp " << _maxWarp << "! " << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

void Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Ship::checkCore()
{
    if (!_core || !_core->getReactor())
        return;
    std::cout << "USS " << _name << ": The core is " << (_core->getReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

void Ship::promote(Captain* cap)
{
    if (!cap)
        return;
    _captain = cap;
    std::cout << cap->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp)
        return false;
    if (_location == d)
        return false;
    if (!_core || !_core->getReactor() || !_core->getReactor()->isStable())
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

int Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Ship::setTorpedo(int val)
{
    if (val < 0)
        val = 0;
    _photonTorpedo = val;
}
    
void Ship::fire(Borg::Ship* target)
{
    if (getTorpedo() > 0 && target)
    {
        setTorpedo(getTorpedo() - 1);
        target->setShield(target->getShield() - 50);
        std::cout << _name << ": Firing on target. " << getTorpedo() << " torpedoes remaining." << std::endl;
    }
    else
        std::cout << _name << ": No more torpedo to fire, " << (_captain ? _captain->getName() : "") << "!" << std::endl;
}

void Ship::fire(int torpedoes, Borg::Ship* target)
{
    if (getTorpedo() > 0 && target)
    {
        if (getTorpedo() < torpedoes)
        {
            std::cout << _name << ": No enough torpedoes to fire, " << (_captain ? _captain->getName() : "") << "!" << std::endl;
            return;
        }
        setTorpedo(getTorpedo() - torpedoes);
        target->setShield(target->getShield() - (50 * torpedoes));
        std::cout << _name << ": Firing on target. " << getTorpedo() << " torpedoes remaining." << std::endl;
    }
    else
        std::cout << _name << ": No more torpedo to fire, " << (_captain ? _captain->getName() : "") << "!" << std::endl;
}

Captain::Captain(std::string name) :
    _name(name), _age(42)
{
}

std::string Captain::getName()
{
    return _name;
}

int Captain::getAge()
{
    return _age;
}

void Captain::setAge(int age)
{
    _age = age;
}

Ensign::Ensign(std::string name) :
    _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

} // !namespace Starfleet

Ship::Ship(int length, int width, std::string name, short maxWarp) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(NULL), _home(VULCAN), _location(VULCAN)

{
    if (_maxWarp > 1)
        _maxWarp = 1;
    std::cout << "The independant ship " << _name << " just finished its construction. It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

void Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Ship::checkCore()
{
    if (!_core || !_core->getReactor())
        return;
    std::cout << _name << ": The core is " << (_core->getReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp)
        return false;
    if (_location == d)
        return false;
    if (!_core || !_core->getReactor() || !_core->getReactor()->isStable())
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

WarpSystem::Core* Ship::getCore()
{
    return _core;
}

} // !namespace Federation

