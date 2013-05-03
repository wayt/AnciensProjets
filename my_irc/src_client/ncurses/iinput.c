/*
** iinput.c for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Apr 27 13:31:32 2013 fabien casters
** Last update Sun Apr 28 15:43:34 2013 fabien casters
*/

#include <string.h>
#include "iinput.h"

void		refresh_input(t_interface *in, char *str)
{
  int		index;

  mvwprintw(WIN(w_input), 1, 1, "%*s", 58, " ");
  index = (strlen(str) > 58) ? strlen(str) - 58 : 0;
  mvwaddstr(WIN(w_input), 1, 1, str + index);
  wrefresh(WIN(w_input));
}
