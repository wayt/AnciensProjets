/*
** ToyStory.h for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d13-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 16:03:03 2013 maxime ginters
** Last update Mon Jan 21 17:00:25 2013 maxime ginters
*/

#ifndef TOYSTORY_H_
# define TOYSTORY_H_

#include <fstream>
#include <iostream>
#include <string>
#include "Toy.h"

class ToyStory
{
public:
    static void tellMeAStory(std::string const& filename, Toy& toy1, bool(Toy::*func1)(std::string const&), Toy& toy2, bool(Toy::*func2)(std::string const&));
    static bool execute(Toy& toy, bool (Toy::*func)(std::string const& str), std::string const& str);
};

#endif /* !TOYSTORY_H_ */
