/*
** Margarita.h for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:17:09 2013 maxime ginters
** Last update Sat Apr 20 00:57:00 2013 maxime ginters
*/

#ifndef MARGARITA_H_
# define MARGARITA_H_

#include "Pizza.h"

class Margarita : public Pizza
{
public:
    Margarita(TaillePizza size);

    uint32 getCraftTime(float mult) const;
    void getIngredientsList(std::list<Ingredients>& list) const;
};


#endif /* !MARGARITA_H_ */
