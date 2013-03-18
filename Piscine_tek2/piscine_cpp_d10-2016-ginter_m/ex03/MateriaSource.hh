/*
** MateriaSource.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 01:18:19 2013 maxime ginters
** Last update Sat Jan 19 01:44:07 2013 maxime ginters
*/

#ifndef MATERIASOURCE_H_
# define MATERIASOURCE_H_

#include "AMateria.hh"
#include "IMateriaSource.hh"
#include "Character.hh"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    virtual ~MateriaSource() {}

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);
private:
    AMateria* _inventory[4];
};

#endif /* !MATERIASOURCE_H_ */
