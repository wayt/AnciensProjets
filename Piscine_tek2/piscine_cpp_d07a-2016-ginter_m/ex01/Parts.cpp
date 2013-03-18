/*
** Parts.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 21:43:26 2013 maxime ginters
** Last update Tue Jan 15 21:43:26 2013 maxime ginters
*/

#include <iostream>
#include "Parts.h"

Arms::Arms(std::string const& serial, bool functionnal) :
    _serial(serial), _functionnal(functionnal)
{
}

bool Arms::isFunctionnal() const
{
    return _functionnal;
}

std::string const& Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string const& serial, bool functionnal) :
    _serial(serial), _functionnal(functionnal)
{
}

bool Legs::isFunctionnal() const
{
    return _functionnal;
}

std::string const& Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

Head::Head(std::string const& serial, bool functionnal) :
    _serial(serial), _functionnal(functionnal)
{
}

bool Head::isFunctionnal() const
{
    return _functionnal;
}

std::string const& Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}
