/*
** Victim.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 09:33:26 2013 maxime ginters
** Last update Fri Jan 18 10:00:12 2013 maxime ginters
*/

#ifndef VICTIM_H_
# define VICTIM_H_

#include <iostream>
#include <string>

class Victim
{
public:
    Victim(std::string const& name);
    virtual ~Victim();

    std::string const& getName() const;
    virtual void getPolymorphed() const;
protected:
    std::string const _name;
};

std::ostream& operator<<(std::ostream& stream, Victim const& unit);

#endif /* !VICTIM_H_ */
