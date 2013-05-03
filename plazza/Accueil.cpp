/*
** Accueil.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 13:57:43 2013 maxime ginters
** Last update Sun Apr 21 14:19:52 2013 maxime ginters
*/

#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <csignal>
#include <algorithm>
#include <cstring>
#include "Accueil.h"
#include "Utils.hpp"
#include "Kitchen.h"
#include "Log.h"
#include "CommunicatorAK.h"
#include "Runnable.h"

kitchenInfo::kitchenInfo(int32 pi) : pizzaCount(0), pid(pi)
{}

Accueil::Accueil() : _cookTimeMultiplicator(1.0f),
    _cookPerKitchen(0), _ingredientRegenTime(0),
     _typePizzaToStr(), _taillePizzaToStr(),
    _kitchenInfos(), _run(false),
    _plazza(NULL)
{
    _typePizzaToStr.push_back(std::pair<TypePizza, std::string>(REGINA, "regina"));
    _typePizzaToStr.push_back(std::pair<TypePizza, std::string>(MARGARITA, "margarita"));
    _typePizzaToStr.push_back(std::pair<TypePizza, std::string>(AMERICAINE, "americaine"));
    _typePizzaToStr.push_back(std::pair<TypePizza, std::string>(FANTASIA, "fantasia"));

    _taillePizzaToStr.push_back(std::pair<TaillePizza, std::string>(S, "s"));
    _taillePizzaToStr.push_back(std::pair<TaillePizza, std::string>(M, "m"));
    _taillePizzaToStr.push_back(std::pair<TaillePizza, std::string>(L, "l"));
    _taillePizzaToStr.push_back(std::pair<TaillePizza, std::string>(XL, "xl"));
    _taillePizzaToStr.push_back(std::pair<TaillePizza, std::string>(XXL, "xxl"));
}

Accueil::~Accueil()
{
    delete _plazza;
}

void Accueil::stop()
{
  _run = false;
  std::map<uint32, kitchenInfo>::const_iterator itr = _kitchenInfos.begin();
  for (; itr != _kitchenInfos.end(); ++itr)
      kill(itr->second.pid, SIGKILL);
}

bool Accueil::initialize(int ac, char **av)
{
    sLog->out("Initialize accueil ...");
    if (ac < 4)
        return false;

    _cookTimeMultiplicator = to<float>(av[1]);
    _cookPerKitchen = to<uint32>(av[2]);
    _ingredientRegenTime = to<uint32>(av[3]);
    _plazza = new Graphic::Plazza();

    try
    {
        sCommunicatorAK->init();
    }
    catch (std::exception const& e)
    {
        sLog->error("Error: %s", e.what());
        return false;
    }

    return true;
}

void Accueil::run()
{
    _run = true;
    while (_run)
    {
        _plazza->draw();
        _plazza->updateInput();
        std::string str = "";
        *sCommunicatorAK >> str;
        if (str.empty())
        {
            usleep(5000); // 10ms
            continue;
        }
        command* cmd = getCommands();
        std::vector<std::string> elems;
        split(str, '\n', elems);
        for (std::vector<std::string>::const_iterator itr = elems.begin(); itr != elems.end(); ++itr)
        {
            std::string const& sstr = *itr;
            if (!sstr.empty())
            {
                for (uint32 i = 0; cmd[i].cmd != NULL; ++i)
                {
                    if (::strncmp(cmd[i].cmd, sstr.c_str(), ::strlen(cmd[i].cmd)) == 0)
                    {
                        (this->*cmd[i].func)(sstr);
                        _plazza->draw();
                        break;
                    }
                }
            }
        }
    }
}

uint32 Accueil::createKitchen()
{
    uint32 id = getFreeKitchenId();
    int32 fk = -1;

    sLog->out("Create new kitchen id : %u", id);

    fk = fork();
    if (fk == -1)
    {
        sLog->error("Error: fail to fork kitchen");
        return 0;
    }
    else if (fk == 0)
    {
        try
        {
            Kitchen kitchen(id, _cookTimeMultiplicator, _cookPerKitchen, _ingredientRegenTime);
            kitchen.run();
        }
        catch (std::exception const& e)
        {
            sLog->error("Error: %s", e.what());
        }
        std::exit(0);
    }
    // else
    try
    {
        sCommunicatorAK->addKitchen(id);
        _kitchenInfos.insert(std::pair<uint32, kitchenInfo>(id, kitchenInfo(fk)));
        _plazza->addKitchen(id, _cookPerKitchen);
        for (uint32 i = 0; i < INGREDIENTS_COUNT; ++i)
            _plazza->setIngredientCount(id, (Ingredients)i, 5);
    }
    catch (std::exception const& e)
    {
        sLog->error("Error: %s", e.what());
        return 0;
    }

    return id;
}

uint32 Accueil::getFreeKitchenId() const
{
    uint32 id = 1;
    for (;;)
    {
        std::map<uint32, kitchenInfo>::const_iterator itr = _kitchenInfos.find(id);
        if (itr == _kitchenInfos.end())
            return id;
        ++id;
    }
}

uint32 Accueil::getKitchenCount() const
{
    return _kitchenInfos.size();
}

void Accueil::readCommandList(std::string const& str)
{
    std::vector<std::string> commands;
    split(str, ';', commands);

    for (std::vector<std::string>::iterator itr = commands.begin(); itr != commands.end(); ++itr)
        _processCommand(*itr);
}

void Accueil::_processCommand(std::string const& cmd)
{
    if (cmd.empty())
        return;
    if (cmd == "bye" || cmd == "exit")
    {
        stop();
        return;
    }

    std::string str = "";
    std::stringstream ss(cmd);
    try
    {
        ss >> str;
        TypePizza type = _strToTypePizza(str);
        ss >> str;
        TaillePizza size = _strToTaillePizza(str);
        ss >> str;
        uint32 count = _strToPizzaCount(str);
        _registerCommand(type, size, count);
    }
    catch (std::exception const& e)
    {
        sLog->error("Error: %s [%s]", e.what(), str.c_str());
    }
}

TypePizza Accueil::_strToTypePizza(std::string& str) const
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    typePizzaToStrList::const_iterator itr = _typePizzaToStr.begin();
    for (; itr != _typePizzaToStr.end(); ++itr)
        if (itr->second == str)
            return itr->first;
    throw ExceptInvalidCommand();
}

TaillePizza Accueil::_strToTaillePizza(std::string& str) const
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    taillePizzaToStrList::const_iterator itr = _taillePizzaToStr.begin();
    for (; itr != _taillePizzaToStr.end(); ++itr)
        if (itr->second == str)
            return itr->first;
    throw ExceptInvalidCommand();
}

uint32 Accueil::_strToPizzaCount(std::string& str) const
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (str[0] != 'x' || str.length() <= 1)
        throw ExceptInvalidCommand();
    const char* cstr = str.c_str();
    uint32 count = 0;
    count = to<uint32>(cstr + 1);
    if (count == 0)
        throw ExceptInvalidCommand();
    return count;
}

void Accueil::_registerCommand(TypePizza type, TaillePizza size, uint32 count)
{
    while (count > 0)
    {
        uint32 id = getLowerKitchen();
        if (id == 0)
            break;

        std::map<uint32, kitchenInfo>::iterator itr = _kitchenInfos.find(id);
        if (itr == _kitchenInfos.end())
            break;
        kitchenInfo& info = itr->second;
        info.pizzaCount += 1;
        count -= 1;
        _plazza->setRemaining(id, info.pizzaCount);

        std::stringstream ss;
        ss  << "COMMAND:" << type << ":" << size << ":1";
        (*sCommunicatorAK)[itr->first] << ss.str();
    }
    if (count > 0)
    {
        if (createKitchen() != 0)
            _registerCommand(type, size, count);
    }
}

uint32 Accueil::getLowerKitchen() const
{
    uint32 id = 0;
    uint32 count = 0xFFFFFFFF;

    std::map<uint32, kitchenInfo>::const_iterator itr = _kitchenInfos.begin();
    for (; itr != _kitchenInfos.end() && count > 0; ++itr)
    {
        kitchenInfo const& info = itr->second;
        if (info.pizzaCount < count)
        {
            count = info.pizzaCount;
            id = itr->first;
        }
    }
    return count >= (2 * _cookPerKitchen) ? 0 : id;
}

Accueil::command* Accueil::getCommands() const
{
    static command cmd[] = {
        {"PIZZA", &Accueil::handleReceivPizza},
        {"UPDATEINGREDIENT:", &Accueil::handleUpdateIngredients},
        {"COOKSTATUS:", &Accueil::handleCookStatus},
        {"CLOSE:", &Accueil::handleKitchenClose},
        {NULL, NULL}
    };
    return cmd;
}

void Accueil::handleReceivPizza(std::string const& msg)
{
    std::vector<std::string> elems;
    split(msg, ':', elems);
    if (elems.size() < 4)
        return;
    uint32 id = to<uint32>(elems[3].c_str());
    std::map<uint32, kitchenInfo>::iterator itr = _kitchenInfos.find(id);
    if (itr == _kitchenInfos.end())
        return;
    itr->second.pizzaCount -= 1;
    _plazza->setRemaining(id, itr->second.pizzaCount);
}

void Accueil::handleUpdateIngredients(std::string const& msg)
{
    std::vector<std::string> elems;
    split(msg, ':', elems);
    if (elems.size() < 4)
        return;
    Ingredients ingre = (Ingredients)to<uint32>(elems[1].c_str());
    uint32 count = to<uint32>(elems[2].c_str());
    uint32 idKitchen = to<uint32>(elems[3].c_str());
    _plazza->setIngredientCount(idKitchen, ingre, count);
}

void Accueil::handleCookStatus(std::string const& msg)
{
    std::vector<std::string> elems;
    split(msg, ':', elems);
    if (elems.size() < 4)
        return;
    StateCook state = (StateCook)to<uint32>(elems[1].c_str());
    uint32 idCook = to<uint32>(elems[2].c_str());
    uint32 idKitchen = to<uint32>(elems[3].c_str());
    _plazza->setCookState(idKitchen, idCook, state);
}

void Accueil::handleKitchenClose(std::string const& msg)
{
    std::vector<std::string> elems;
    split(msg, ':', elems);
    if (elems.size() < 2)
        return;
    uint32 id = to<uint32>(elems[1].c_str());
    _kitchenInfos.erase(id);
    _plazza->removeKitchen(id);
}

void Accueil::resize()
{
    _plazza->resize();
}
