/*
** Fantasia.cpp for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:34:19 2013 maxime ginters
** Last update Sat Apr 20 00:59:47 2013 maxime ginters
*/

#include "Fantasia.h"

Fantasia::Fantasia(TaillePizza size) : Pizza(FANTASIA, size)
{}

uint32 Fantasia::getCraftTime(float mult) const
{
    return mult * (4 * IN_MILLISECONDS);
}

void Fantasia::getIngredientsList(std::list<Ingredients>& list) const
{
    list.push_back(DOE);
    list.push_back(TOMATO);
    list.push_back(EGGPLANT);
    list.push_back(GOAT_CHEESE);
    list.push_back(CHIEF_LOVE);
}
