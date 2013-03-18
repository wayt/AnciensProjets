/*
** Ice.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:36:12 2013 maxime ginters
** Last update Sat Jan 19 01:50:48 2013 maxime ginters
*/

#ifndef ICE_H_
# define ICE_H_

#include "AMateria.hh"
#include "ICharacter.hh"

class Ice : public AMateria
{
public:
    Ice();
    virtual ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif /* !ICE_H_ */
