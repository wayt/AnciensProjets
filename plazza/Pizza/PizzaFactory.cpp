/*
** PizzaFactory.cpp for Pizza in /Storage/Epitech/Plazza/Pizza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 17 11:50:14 2013 maxime ginters
** Last update Wed Apr 17 13:14:13 2013 maxime ginters
*/

#include "PizzaFactory.h"
#include "Regina.h"
#include "Margarita.h"
#include "Americana.h"
#include "Fantasia.h"

PizzaFactory::PizzaFactory() : _factoryMap()
{
    _factoryMap.insert(std::pair<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const>(REGINA, &PizzaFactory::create<Regina>));
    _factoryMap.insert(std::pair<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const>(MARGARITA, &PizzaFactory::create<Margarita>));
    _factoryMap.insert(std::pair<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const>(AMERICAINE, &PizzaFactory::create<Americana>));
    _factoryMap.insert(std::pair<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const>(FANTASIA, &PizzaFactory::create<Fantasia>));
}

Pizza* PizzaFactory::createPizza(TypePizza type, TaillePizza size) const
{
    std::map<TypePizza, Pizza* (PizzaFactory::*)(TaillePizza) const>::const_iterator itr = _factoryMap.find(type);
    if (itr == _factoryMap.end())
       throw ExceptInvalidPizza();
    return ((this->*itr->second)(size));
}

template<class T>
Pizza* PizzaFactory::create(TaillePizza size) const
{
    return new T(size);
}

template Pizza* PizzaFactory::create<Regina>(TaillePizza size) const;
template Pizza* PizzaFactory::create<Margarita>(TaillePizza size) const;
template Pizza* PizzaFactory::create<Americana>(TaillePizza size) const;
template Pizza* PizzaFactory::create<Fantasia>(TaillePizza size) const;
