/*
** Fruit.cpp for piscine_cpp_d14m-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d14m-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 22 13:57:19 2013 maxime ginters
** Last update Tue Jan 22 14:40:43 2013 maxime ginters
*/

#include "Fruit.h"

Fruit::Fruit(std::string const& name, int vitamin) :
    _name(name), _vitamins(vitamin)
{}

Fruit::~Fruit()
{}

std::string const& Fruit::getName() const
{
    return _name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}
