/*
** NCursesGraph.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src/Display/NCurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 21:33:58 2013 fabien casters
** Last update Tue Jan 29 21:37:34 2013 fabien casters
*/

#include "NCursesGraph.h"

void NCursesGraph::display()
{
    mvwaddstr(_window, 1, 1, _values.back().c_str());
    ::wrefresh(_window);
}
