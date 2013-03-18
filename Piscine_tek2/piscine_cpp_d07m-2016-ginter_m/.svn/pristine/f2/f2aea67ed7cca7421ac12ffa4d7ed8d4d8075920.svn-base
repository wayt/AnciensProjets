/*
** BorgQueen.hh for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 16:16:41 2013 maxime ginters
** Last update Tue Jan 15 16:53:04 2013 maxime ginters
*/

#ifndef BORGQUEEN_H_
# define BORGQUEEN_H_

#include "Federation.hh"
#include "Borg.hh"
#include "Destination.hh"

namespace Borg
{

class BorgQueen
{
public:
    explicit BorgQueen();
    virtual ~BorgQueen() {}

    bool (Borg::Ship::*movePtr)(Destination);
    void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
    void (Borg::Ship::*destroyPtr)(Federation::Ship*);

    bool move(Borg::Ship* ship, Destination dest);
    void fire(Borg::Ship* ship, Federation::Starfleet::Ship* target);
    void destroy(Borg::Ship* ship, Federation::Ship* target);
};

}

#endif /* !BORGQUEEN_H_ */
