/*
** MateriaSource.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 01:20:45 2013 maxime ginters
** Last update Sat Jan 19 01:20:45 2013 maxime ginters
*/

#include "MateriaSource.hh"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
        if (!_inventory[i])
        {
            _inventory[i] = m->clone();
            return;
        }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            if (_inventory[i]->getType() == type)
                return _inventory[i]->clone();
    return NULL;
}
