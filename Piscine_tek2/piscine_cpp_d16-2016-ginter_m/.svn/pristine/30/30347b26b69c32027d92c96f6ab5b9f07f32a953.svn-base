/*
** DomesticKoala.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 13:32:50 2013 maxime ginters
** Last update Thu Jan 24 14:11:12 2013 maxime ginters
*/

#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction& action) :
    _action(action), _knowAction(256)
{}

DomesticKoala::~DomesticKoala()
{}

DomesticKoala::DomesticKoala(DomesticKoala const& other) :
    _action(other._action), _knowAction(other._knowAction)
{}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const& other)
{
    _action = other._action;
    _knowAction = other._knowAction;
    return *this;
}

std::vector<DomesticKoala::methodPointer_t> const*  DomesticKoala::getActions() const
{
    return &_knowAction;
}

void DomesticKoala::learnAction(unsigned char c, methodPointer_t ptr)
{
    _knowAction[c] = ptr;
}

void DomesticKoala::unlearnAction(unsigned char c)
{
    _knowAction[c] = NULL;
}

void DomesticKoala::doAction(unsigned char c, std::string const& str)
{
    methodPointer_t func = _knowAction[c];
    if (func)
        (_action.*func)(str);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    _action = action;
}
