/*
** Sorcerer.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 09:20:39 2013 maxime ginters
** Last update Fri Jan 18 10:22:48 2013 maxime ginters
*/

#ifndef SORCERER_H_
# define SORCERER_H_

#include <iostream>
#include <string>
#include "Victim.hh"

class Sorcerer
{
public:
    explicit Sorcerer(std::string const& name, std::string const& title);
    virtual ~Sorcerer();

    std::string const& getName() const;
    std::string const& getTitle() const;

    void polymorph(Victim const& unit) const;
protected:
    std::string const _name;
    std::string const _title;
};

std::ostream& operator<<(std::ostream& stream, Sorcerer const& unit);

#endif /* !SORCERER_H_ */
