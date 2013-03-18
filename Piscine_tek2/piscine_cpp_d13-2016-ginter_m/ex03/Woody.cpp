/*
** Woody.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d13-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 13:44:53 2013 maxime ginters
** Last update Mon Jan 21 14:10:35 2013 maxime ginters
*/

#include "Woody.h"

Woody::Woody(std::string const& name, std::string const& filename) :
    Toy(WOODY, name, filename)
{}

Woody::~Woody()
{}

void Woody::speak(std::string const& speech)
{
    std::cout << "WOODY: ";
    Toy::speak(speech);
}
