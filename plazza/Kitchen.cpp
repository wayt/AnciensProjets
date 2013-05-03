/*
** Kitchen.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 14:04:01 2013 maxime ginters
** Last update Sun Apr 21 13:15:27 2013 maxime ginters
*/

#include <unistd.h>
#include <ctime>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "ScopLock.h"
#include "Kitchen.h"
#include "Utils.hpp"
#include "Log.h"

Kitchen::Kitchen(uint32 id, float cookTime, uint32 nbCook, uint32 regenTime) :
    _id(id), _cookTime(cookTime), _regenTime(regenTime),
    _cooks(nbCook), _regenTimer(0), _ingredientsMap(),
    _ingredientsMutex(), _communicator(id), _lastPizza(GetMSTime()),
    _inProgress(0)
{
    for (uint8 i = 0; i < INGREDIENTS_COUNT; ++i)
        _ingredientsMap.insert(std::pair<Ingredients, uint32>((Ingredients)i, 5));
    for (uint32 i = 0; i < nbCook; ++i)
    {
        _cooks[i] = new Cook(i + 1, this, cookTime);
        _cooks[i]->run();
    }
}

void Kitchen::run()
{
    uint64 prevTime = GetMSTime();
    for (;;)
    {
        uint32 diff = GetMSTimeDiffToNow(prevTime);
        prevTime = GetMSTime();
        update(diff);
        usleep(50 * IN_MILLISECONDS);
    }
}

uint32 Kitchen::getId() const
{
    return _id;
}

void Kitchen::update(uint32 const diff)
{
    if (_inProgress == 0 && GetMSTimeDiffToNow(_lastPizza) >= 5 * IN_MILLISECONDS)
    {
        send("CLOSE");
        sLog->out("Kitchen %u idle, closing", _id);
        std::exit(0);
    }
    if (_regenTimer >= _regenTime)
    {
        ScopLock lock(_ingredientsMutex);
        for (uint8 i = 0; i < INGREDIENTS_COUNT; ++i)
            _regenerate((Ingredients)i);
        _ingredientsCond.notify();
        _regenTimer = 0;
    }
    else
        _regenTimer += diff;

    std::string str = "";
    _communicator >> str;
    std::vector<std::string> elems;
    split(str, '\n', elems);
    for (std::vector<std::string>::const_iterator itr = elems.begin(); itr != elems.end(); ++itr)
    {
        std::string const& sstr = *itr;
        if (!sstr.empty())
        {
            if (::strncmp("COMMAND:", sstr.c_str(), 8) == 0)
            {
                std::vector<std::string> elems;
                split(sstr, ':', elems);
                uint32 type = to<uint32>(elems[1].c_str());
                uint32 size = to<uint32>(elems[2].c_str());
                uint32 count = to<uint32>(elems[3].c_str());
                for (uint32 i = 0; i < count; ++i)
                    _registerPizza((TypePizza)type, (TaillePizza)size);
            }
        }
    }
}

void Kitchen::_regenerate(Ingredients ingre)
{
    std::map<Ingredients, uint32>::iterator itr = _ingredientsMap.find(ingre);
    if (itr == _ingredientsMap.end())
        _ingredientsMap.insert(std::pair<Ingredients, uint32>(ingre, 1));
    else
        itr->second += 1;
    std::stringstream ss;
    ss << "UPDATEINGREDIENT:";
    ss << (uint32)ingre;
    ss << ":";
    ss << _ingredientsMap[ingre];
    send(ss.str());
}

void Kitchen::takeIngredients(std::list<Ingredients> const& ingres)
{
    ScopLock lock(_ingredientsMutex);
    for (;;)
    {
        bool noFound = false;
        for (std::list<Ingredients>::const_iterator itr = ingres.begin();
                itr != ingres.end(); ++itr)
        {
            std::map<Ingredients, uint32>::iterator itr2 = _ingredientsMap.find(*itr);
            if (itr2 == _ingredientsMap.end() || itr2->second == 0)
            {
                noFound = true;
                break;
            }
        }
        if (!noFound)
            break;
        _ingredientsCond.wait(_ingredientsMutex);
    }
    for (std::list<Ingredients>::const_iterator itr = ingres.begin();
                itr != ingres.end(); ++itr)
    {
            _ingredientsMap[*itr] -= 1;
            std::stringstream ss;
            ss << "UPDATEINGREDIENT:";
            ss << *itr;
            ss << ":";
            ss << _ingredientsMap[*itr];
            send(ss.str());
    }
}

void Kitchen::_registerPizza(TypePizza type, TaillePizza size)
{
    Pizza* pizz = NULL;
    try
    {
        pizz = sPizzaFactory->createPizza(type, size);
    }
    catch (std::exception const& e)
    {
        sLog->error("Error: %s", e.what());
        return;
    }
    _queue.add(pizz);
    sLog->out("New pizza added in kitchen %u", _id);
}

Pizza* Kitchen::takeNewPizza()
{
    Pizza* pizz = _queue.get();
    _lastPizza = GetMSTime();
    ++_inProgress;
    return pizz;
}

void Kitchen::pizzaFinished(Pizza* pizz)
{
    std::stringstream ss;
    ss << *pizz;
    send(ss.str());
    delete pizz;
    _lastPizza = GetMSTime();
    --_inProgress;
}

void Kitchen::send(std::string const& str) const
{
    std::stringstream ss;
    ss << str << ":" << _id;
    _communicator << ss.str();
}
