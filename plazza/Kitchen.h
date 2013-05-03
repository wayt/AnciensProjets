/*
** Kitchen.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 14:04:01 2013 maxime ginters
** Last update Sun Apr 21 13:14:25 2013 maxime ginters
*/

#ifndef KITCHEN_H_
# define KITCHEN_H_

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <pthread.h>
#include "SharedDefines.h"
#include "Cook.h"
#include "Pizza.h"
#include "SynchronizedQueue.hpp"
#include "PizzaFactory.h"
#include "CommunicatorKA.h"

class Kitchen
{
public:
    Kitchen(uint32 id, float cookTime, uint32 nbCook, uint32 regenTime);

    void run();

    void update(uint32 const diff);

    void takeIngredients(std::list<Ingredients> const& ingres);
    Pizza* takeNewPizza();
    void pizzaFinished(Pizza* pizz);

    uint32 getId() const;
    void send(std::string const& str) const;
protected:
    void _regenerate(Ingredients ingre);

    void _registerPizza(TypePizza type, TaillePizza size);


    uint32 _id;
    float _cookTime;
    uint32 _regenTime;
    std::vector<Cook*> _cooks;
    SynchronizedQueue<Pizza> _queue;
    uint32 _regenTimer;

    std::map<Ingredients, uint32> _ingredientsMap;
    Mutex _ingredientsMutex;
    ConditionalVariable _ingredientsCond;

    CommunicatorKA _communicator;
    uint32 _lastPizza;
    uint32 _inProgress;
};

#endif /* !KITCHEN_H_ */
