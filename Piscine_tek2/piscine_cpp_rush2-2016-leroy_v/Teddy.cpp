/*
** Teddy.cpp for Rush2 in /home/leroy_v/Epitech/piscine2013/Rush2
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 19 17:27:17 2013 vincent leroy
** Last update Sat Jan 19 23:05:15 2013 fabien casters
*/

#include "Teddy.h"

Teddy::Teddy() : Toy("bisounours", TYPE_TEDDY)
{
}

void Teddy::isTaken()
{
    Toy::isTaken();
    std::cout << "gra hu" << std::endl;
}
