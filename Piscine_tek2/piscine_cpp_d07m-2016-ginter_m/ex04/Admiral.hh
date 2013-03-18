/*
** Admiral.hh for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 15:45:16 2013 maxime ginters
** Last update Tue Jan 15 16:50:35 2013 maxime ginters
*/

#ifndef ADMIRAL_H_
# define ADMIRAL_H_

#include <string>
#include "Federation.hh"
#include "Borg.hh"
#include "Destination.hh"

namespace Federation
{

namespace Starfleet
{

class Admiral
{
public:
    explicit Admiral(std::string name);
    virtual ~Admiral() {}

    void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship*);
    bool (Federation::Starfleet::Ship::*movePtr)(Destination);
    void fire(Federation::Starfleet::Ship* ship, Borg::Ship* target);
    bool move(Federation::Starfleet::Ship* ship, Destination dest);
private:
    std::string _name;
};

} // !namespace Starfleet

} // !namespace Federation

#endif /* !ADMIRAL_H_ */
