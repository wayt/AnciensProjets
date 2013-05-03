/*
** Regina.cpp for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:21:37 2013 maxime ginters
** Last update Sat Apr 20 00:59:48 2013 maxime ginters
*/

#include "Regina.h"

Regina::Regina(TaillePizza size) : Pizza(REGINA, size)
{}

uint32 Regina::getCraftTime(float mult) const
{
    return mult * (2 * IN_MILLISECONDS);
}

void Regina::getIngredientsList(std::list<Ingredients>& list) const
{
    list.push_back(DOE);
    list.push_back(TOMATO);
    list.push_back(GRUYERE);
    list.push_back(HAM);
    list.push_back(MUSHROOMS);
}
