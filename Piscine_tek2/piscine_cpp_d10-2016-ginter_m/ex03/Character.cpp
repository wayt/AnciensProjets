/*
** Character.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:56:58 2013 maxime ginters
** Last update Sat Jan 19 00:56:58 2013 maxime ginters
*/

#include "Character.hh"

Character::Character(std::string const& name) :
    _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(Character const& other) :
    _name(other.getName())
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
    }
}

Character::~Character()
{}
    
Character& Character::operator=(Character const& other)
{
    _name = other._name;
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
    }
    return *this;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (!_inventory[idx])
        return;
    _inventory[idx]->use(target);

}

std::string const& Character::getName() const
{
    return _name;
}
