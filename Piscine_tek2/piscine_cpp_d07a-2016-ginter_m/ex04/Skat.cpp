/*
** Skat.cpp for piscine_cpp_d07a-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 20:50:46 2013 maxime ginters
** Last update Tue Jan 15 20:50:46 2013 maxime ginters
*/

#include <iostream>
#include "Skat.h"

Skat::Skat(std::string const& name, int stimPaks, int serial, int x, int y, Phaser::AmmoType type) : _name(name), _stimPaks(stimPaks), _kreog(x, y, serial), _phaser(20, type)
{
    
}

Skat::~Skat() {}

unsigned int& Skat::stimPaks()
{
    return _stimPaks;
}

const std::string& Skat::name() const
{
    return _name;
}

void Skat::shareStimPaks(int number, unsigned int& stock)
{
    if ((int)_stimPaks < number)
    {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    _stimPaks -= number;
    stock += number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something ?" << std::endl;
    _stimPaks += number;
}

void Skat::useStimPaks()
{
    if (_stimPaks > 0)
    {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        --_stimPaks;
    }
    else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status() const
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir !" << std::endl;
}

void Skat::fire()
{
    _phaser.fire();
}

void Skat::locate() const
{
    _kreog.locateSquad();
}

void Skat::reload()
{
    _phaser.reload();
}

KreogCom& Skat::com()
{
    return _kreog;
}


