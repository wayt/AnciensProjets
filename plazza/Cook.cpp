/*
** Cook.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 16:20:56 2013 maxime ginters
** Last update Sat Apr 20 00:56:28 2013 maxime ginters
*/

#include <unistd.h>
#include "Cook.h"
#include "Kitchen.h"
#include "Log.h"

Cook::Cook(uint32 id, Kitchen* Kitchen, float cookTime) : Runnable(),
    _id(id), _kitchen(Kitchen), _cookTime(cookTime)
{}

void Cook::operator()()
{
    while (!isStopped())
    {
        sendStatus(WAIT_PIZZA);
        Pizza* pizz = _kitchen->takeNewPizza();
        sLog->out("Cook take new pizza");
        std::list<Ingredients> ingreList;
        pizz->getIngredientsList(ingreList);
        sendStatus(WAIT_INGREDIENT);
        _kitchen->takeIngredients(ingreList);
        sLog->out("Cook take ingredients and start to work");
        uint32 sleepTime = pizz->getCraftTime(_cookTime);
        sendStatus(COOK);
        while (sleepTime >= 1 * IN_MILLISECONDS)
        {
            sleepTime -= 1 * IN_MILLISECONDS;
            sleep(1);
        }
        if (sleepTime > 0)
            usleep(sleepTime * 1000);
        sLog->out("Cook finish pizza");
        _kitchen->pizzaFinished(pizz);
    }
}

void Cook::sendStatus(StateCook s) const
{
    std::stringstream ss;
    ss << "COOKSTATUS:";
    ss << (uint32)s;
    send(ss.str());
}

void Cook::send(std::string const& msg) const
{
    std::stringstream ss;
    ss << msg << ":" << _id;
    _kitchen->send(ss.str());
}
