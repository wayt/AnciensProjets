/*
** Admiral.cpp for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 15:49:28 2013 maxime ginters
** Last update Tue Jan 15 15:49:28 2013 maxime ginters
*/

#include <iostream>
#include "Admiral.hh"

namespace Federation
{

namespace Starfleet
{

Admiral::Admiral(std::string name) : _name(name)
{
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
    movePtr = &Federation::Starfleet::Ship::move;
    firePtr = &Federation::Starfleet::Ship::fire;
}

void Admiral::fire(Federation::Starfleet::Ship* ship, Borg::Ship* target)
{
    if (!ship || !target || !firePtr)
        return;
    std::cout << "On order from Admiral " << _name << ":" <<std::endl;
    (ship->*firePtr)(target);
}

bool Admiral::move(Federation::Starfleet::Ship* ship, Destination dest)
{
    if (!ship || !movePtr)
        return false;
    return (ship->*movePtr)(dest);
}

} // !namespace Starfleet

} // !namespace Federation

