/*
** PizzaFactory.h for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 17 11:50:14 2013 maxime ginters
** Last update Wed Apr 17 13:23:12 2013 maxime ginters
*/

#ifndef PIZZAFACTORY_H_
# define PIZZAFACTORY_H_

#include <map>
#include <exception>
#include "Singleton.hpp"
#include "Pizza.h"

#include "Regina.h"

class PizzaFactory : public Singleton<PizzaFactory>
{
public:
    PizzaFactory();
    Pizza* createPizza(TypePizza type, TaillePizza size) const;

private:
    template<class T>
    Pizza* create(TaillePizza size) const;

    std::map<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const> _factoryMap;

public:
    class ExceptInvalidPizza : public std::exception
    {
        const char* what() const throw()
        {
            return "Invalide pizza type";
        }
    };
};

#define sPizzaFactory PizzaFactory::instance()

#endif /* !PIZZAFACTORY_H_ */
