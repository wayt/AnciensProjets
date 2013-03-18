/*
** Phaser.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 00:54:08 2013 maxime ginters
** Last update Wed Jan 16 00:54:08 2013 maxime ginters
*/

#include <iostream>
#include "Phaser.h"

Phaser::Phaser(int maxAmmo, AmmoType type) :
    _maxAmmo(maxAmmo)
{
    for(int i = 0; i <= ROCKET; ++i)
        _currentAmmo[i] = _maxAmmo;
    if (type > ROCKET)
        type = REGULAR;
    _type = type;
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (_currentAmmo[_type] == Empty)
    {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    --_currentAmmo[_type];
    if (_type == REGULAR)
        std::cout << Sounds::Regular << std::endl;
    else if (_type == PLASMA)
        std::cout << Sounds::Plasma << std::endl;
    else if (_type == ROCKET)
        std::cout << Sounds::Rocket << std::endl;
}

void Phaser::ejectClip()
{
    _currentAmmo[_type] = 0;
}

void Phaser::changeType(AmmoType newType)
{
    if (newType > ROCKET)
        return;
    _type = newType;
    std::cout << "Switching ammo to type : ";
    switch (_type)
    {
        case REGULAR:
            std::cout << "regular" << std::endl;
            break;
        case PLASMA:
            std::cout << "plasma" << std::endl;
            break;
        case ROCKET:
            std::cout << "rocket" << std::endl;
            break;
    }
}

void Phaser::reload()
{
    std::cout << "Reloading ..." << std::endl;
    _currentAmmo[_type] = _maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (type > ROCKET)
        return;
    if (_currentAmmo[type] == _maxAmmo)
    {
        std::cout << "Clip full" << std::endl;
        return;
    }
    ++_currentAmmo[type];
}

int Phaser::getCurrentAmmos() const
{
    return _currentAmmo[_type];
}
