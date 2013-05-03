/*
** Margarita.cpp for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:17:09 2013 maxime ginters
** Last update Sat Apr 20 00:57:10 2013 maxime ginters
*/

#include "Margarita.h"

Margarita::Margarita(TaillePizza size) : Pizza(MARGARITA, size)
{}

uint32 Margarita::getCraftTime(float mult) const
{
    return mult * (1 * IN_MILLISECONDS);
}

void Margarita::getIngredientsList(std::list<Ingredients>& list) const
{
    list.push_back(DOE);
    list.push_back(TOMATO);
    list.push_back(GRUYERE);
}
