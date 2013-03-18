/*
** NCursesText.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src/Display/NCurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 16:26:34 2013 fabien casters
** Last update Wed Jan 30 03:16:39 2013 vincent leroy
*/

#include "NCursesText.h"

void NCursesText::display()
{
    mvwaddstr(_window, 1, 1, _values.back().c_str());
    mvwaddstr(_window, 1, 1 + _values.back().length(), _unite.c_str());
    mvwaddstr(_window, 1, 1 + _values.back().length() + _unite.length(), "        ");
    ::wrefresh(_window);
}
