/*
** Americana.cpp for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:29:11 2013 maxime ginters
** Last update Sat Apr 20 00:57:20 2013 maxime ginters
*/

#include "Americana.h"

Americana::Americana(TaillePizza size) : Pizza(AMERICAINE, size)
{}

uint32 Americana::getCraftTime(float mult) const
{
    return mult * (2 * IN_MILLISECONDS);
}

void Americana::getIngredientsList(std::list<Ingredients>& list) const
{
    list.push_back(DOE);
    list.push_back(TOMATO);
    list.push_back(GRUYERE);
    list.push_back(STEAK);
}
