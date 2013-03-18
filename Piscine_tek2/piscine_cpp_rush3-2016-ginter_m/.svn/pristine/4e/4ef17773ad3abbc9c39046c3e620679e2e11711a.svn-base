/*
** AMonitorDisplay.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 10:59:24 2013 fabien casters
** Last update Wed Jan 30 02:24:11 2013 fabien casters
*/

#include "AMonitorDisplay.h"

AMonitorDisplay::AMonitorDisplay()
    : _values(), _max(""), _unite("")
{
}

void AMonitorDisplay::addValue(std::string const& value)
{
    _values.push(value);
    if (_values.size() > MAX_VALUE)
        _values.pop();
}

void AMonitorDisplay::setMax(std::string const& max)
{
    _max = max;
}

std::string const& AMonitorDisplay::getUnite() const
{
    return _unite;
}

void AMonitorDisplay::setUnite(std::string const& unite)
{
    _unite = unite;
}
