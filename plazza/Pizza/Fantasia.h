/*
** Fantasia.h for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:33:15 2013 maxime ginters
** Last update Sat Apr 20 00:59:47 2013 maxime ginters
*/

#ifndef FANTASIA_H_
# define FANTASIA_H_

#include "Pizza.h"

class Fantasia : public Pizza
{
public:
    Fantasia(TaillePizza size);

    uint32 getCraftTime(float mult) const;
    void getIngredientsList(std::list<Ingredients>& list) const;
};

#endif /* !FANTASIA_H_ */
