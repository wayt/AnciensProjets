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

Ship::Ship(int length, int width, std::string name, short maxWarp) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(NULL), _captain(NULL)
{
    std::cout << "The ship USS " << _name << " has been finished. It is " << _length << " m in length and " << _width << " m in width." << std::endl << "It can go to Warp " << _maxWarp << "!" << std::endl;
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
    _core(NULL)
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

} // !namespace Federation

