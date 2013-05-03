/*
** Pizza.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 13:07:46 2013 maxime ginters
** Last update Sat Apr 20 00:56:49 2013 maxime ginters
*/

#ifndef PIZZA_H_
# define PIZZA_H_

#include <list>
#include <sstream>
#include "SharedDefines.h"

enum TypePizza
{
    REGINA = 1,
    MARGARITA = 2,
    AMERICAINE = 4,
    FANTASIA = 8
};

enum TaillePizza
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum Ingredients
{
    DOE         = 0,
    TOMATO      = 1,
    GRUYERE     = 2,
    HAM         = 3,
    MUSHROOMS   = 4,
    STEAK       = 5,
    EGGPLANT    = 6,
    GOAT_CHEESE = 7,
    CHIEF_LOVE  = 8
};
#define INGREDIENTS_COUNT 9

class Pizza
{
public:
    Pizza(std::string const& str);
    Pizza(TypePizza type, TaillePizza size);

    virtual ~Pizza() {}

    TypePizza getType() const;
    TaillePizza getSize() const;

    virtual uint32 getCraftTime(float mult) const = 0;
    virtual void getIngredientsList(std::list<Ingredients>& list) const = 0;

private:
    TypePizza _type;
    TaillePizza _size;
};

std::ostream& operator<<(std::ostream& stream, Pizza const& pizz);

#endif /* !PIZZA_H_ */
