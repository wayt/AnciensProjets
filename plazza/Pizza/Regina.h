/*
** Regina.h for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:20:30 2013 maxime ginters
** Last update Sat Apr 20 00:59:48 2013 maxime ginters
*/

#ifndef REGINA_H_
# define REGINA_H_

#include "Pizza.h"

class Regina : public Pizza
{
public:
    Regina(TaillePizza size);

    uint32 getCraftTime(float mult) const;
    void getIngredientsList(std::list<Ingredients>& list) const;
};

#endif /* !REGINA_H_ */
