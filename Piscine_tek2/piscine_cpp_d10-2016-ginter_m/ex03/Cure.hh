/*
** Cure.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:45:57 2013 maxime ginters
** Last update Sat Jan 19 01:49:05 2013 maxime ginters
*/

#ifndef CURE_H_
# define CURE_H_

#include "AMateria.hh"
#include "ICharacter.hh"

class Cure : public AMateria
{
public:
    Cure();
    virtual ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};



#endif /* !CURE_H_ */
