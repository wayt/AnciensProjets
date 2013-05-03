/*
** Accueil.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 13:56:53 2013 maxime ginters
** Last update Sat Apr 20 17:20:10 2013 maxime ginters
*/

#ifndef ACCUEIL_H_
# define ACCUEIL_H_

#include <iostream>
#include <exception>
#include <map>
#include <list>
#include "Pizza.h"
#include "SharedDefines.h"
#include "Singleton.hpp"
#include "Plazza.h"

struct kitchenInfo
{
    uint32 pizzaCount;
    int32 pid;

    kitchenInfo(int32 pi);
};

class Accueil : public Singleton<Accueil>
{
public:
    Accueil();
    ~Accueil();

    void run();
    void stop();

    bool initialize(int ac, char** av);

    uint32 createKitchen();

    void readCommandList(std::string const& str);

    void _processCommand(std::string const& cmd);

    void resize();
protected:

    uint32 getFreeKitchenId() const;
    uint32 getKitchenCount() const;
    uint32 getLowerKitchen() const;


    TypePizza _strToTypePizza(std::string& str) const;
    TaillePizza _strToTaillePizza(std::string& str) const;
    uint32 _strToPizzaCount(std::string& str) const;

    void _registerCommand(TypePizza type, TaillePizza size, uint32 count);

    float _cookTimeMultiplicator;
    uint32 _cookPerKitchen;
    uint32 _ingredientRegenTime;

    typedef std::list<std::pair<TypePizza, std::string> > typePizzaToStrList;
    typedef std::list<std::pair<TaillePizza, std::string> > taillePizzaToStrList;

    typePizzaToStrList _typePizzaToStr;
    taillePizzaToStrList _taillePizzaToStr;

    std::map<uint32, kitchenInfo> _kitchenInfos;
    bool _run;


    class ExceptInvalidCommand : public std::exception
    {
        const char* what() const throw()
        {
            return "Invalide command line";
        }
    };

    void handleReceivPizza(std::string const& msg);
    void handleUpdateIngredients(std::string const& msg);
    void handleCookStatus(std::string const& msg);
    void handleKitchenClose(std::string const& msg);

    struct command
    {
        const char* cmd;
        void (Accueil::*func)(std::string const& msg);
    };

    command* getCommands() const;

    Graphic::Plazza* _plazza;
};

#define sAccueil Accueil::instance()

#endif /* !ACCUEIL_H_ */
