/*
** Squad.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 16:20:22 2013 maxime ginters
** Last update Fri Jan 18 16:20:22 2013 maxime ginters
*/

#include "Squad.hh"

Squad::Squad() : _vector()
{
}

Squad::~Squad()
{
    for (std::vector<ISpaceMarine*>::iterator itr = _vector.begin(); itr != _vector.end(); ++itr)
        delete *itr;
}

int Squad::getCount() const
{
    return _vector.size();
}

ISpaceMarine* Squad::getUnit(int index)
{
    return _vector[index];
}

int Squad::push(ISpaceMarine* unit)
{
    if (!unit)
        return getCount();
    for (std::vector<ISpaceMarine*>::const_iterator itr = _vector.begin(); itr != _vector.end(); ++itr)
        if (unit == *itr)
            return getCount();
    _vector.push_back(unit);
    return getCount();
}
