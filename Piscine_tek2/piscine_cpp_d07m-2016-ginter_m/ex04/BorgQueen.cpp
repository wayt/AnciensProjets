/*
** BorgQueen.cpp for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 16:23:42 2013 maxime ginters
** Last update Tue Jan 15 16:23:42 2013 maxime ginters
*/

#include "BorgQueen.hh"

namespace Borg
{

BorgQueen::BorgQueen()
{
    movePtr = &Borg::Ship::move;
    firePtr = &Borg::Ship::fire;
    destroyPtr = &Borg::Ship::fire;
}

bool BorgQueen::move(Borg::Ship* ship, Destination dest)
{
    if (!ship || !movePtr)
        return false;
    return (ship->*movePtr)(dest);
}

void BorgQueen::fire(Borg::Ship* ship, Federation::Starfleet::Ship* target)
{
    if (!ship || !target || !firePtr)
        return;
    (ship->*firePtr)(target);
}

void BorgQueen::destroy(Borg::Ship* ship, Federation::Ship* target)
{
    if (!ship || !target || !destroyPtr)
        return;
    (ship->*destroyPtr)(target);
}


} // !namsspace Borg
