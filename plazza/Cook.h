/*
** Cook.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 16:19:28 2013 maxime ginters
** Last update Sat Apr 20 00:56:18 2013 maxime ginters
*/

#ifndef COOK_H_
# define COOK_H_

#include <iostream>
#include "SharedDefines.h"
#include "Runnable.h"

enum StateCook
{
    WAIT_PIZZA = 0,
    WAIT_INGREDIENT = 1,
    COOK = 2
};

class Kitchen;

class Cook : public Runnable
{
public:
    Cook(uint32 id, Kitchen* kitchen, float cookTime);

    void operator()();

    void sendStatus(StateCook s) const;
    void send(std::string const& msg) const;
private:
    uint32 _id;
    Kitchen* _kitchen;
    float _cookTime;
};

#endif /* !COOK_H_ */
