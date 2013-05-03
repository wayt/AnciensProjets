/*
** window.h for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 15:48:40 2013 fabien casters
** Last update Fri Apr 26 15:50:47 2013 fabien casters
*/

#ifndef WINDOW_H_
# define WINDOW_H_

#include <curses.h>

struct		s_window
{
  WINDOW	*win;
};
typedef struct s_window t_window;

#endif

