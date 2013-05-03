/*
** Americana.h for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:28:08 2013 maxime ginters
** Last update Sat Apr 20 00:59:47 2013 maxime ginters
*/

#ifndef AMERICANA_H_
# define AMERICANA_H_

#include "Pizza.h"

class Americana : public Pizza
{
public:
    Americana(TaillePizza size);

    uint32 getCraftTime(float mult) const;
    void getIngredientsList(std::list<Ingredients>& list) const;
};

#endif /* !AMERICANA_H_ */
