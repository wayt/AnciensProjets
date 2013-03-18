/*
** Warpsystem.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 09:55:42 2013 maxime ginters
** Last update Tue Jan 15 09:55:42 2013 maxime ginters
*/

#include "Warpsystem.hh"

namespace WarpSystem
{

QuantumReactor::QuantumReactor() :
    _stability(true)
{
}

bool QuantumReactor::isStable()
{
    return _stability;
}
void QuantumReactor::setStability(bool stable)
{
    _stability = stable;
}

Core::Core(QuantumReactor* reacotr) :
    _coreReactor(reacotr)
{
}

QuantumReactor* Core::getReactor()
{
    return _coreReactor;
}

}
