/*
** ichans.c for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 16:34:51 2013 fabien casters
** Last update Sun Apr 28 16:00:59 2013 fabien casters
*/

#include <string.h>
#include <curses.h>
#include "ichans.h"

void		refresh_chans(t_interface *in, t_list list, t_channel *current)
{
  t_channel	*tmp;
  int		i;

  i = 0;
  mvwprintw(WIN(w_chans), 1, 1, "%*s", 78, " ");
  while (list != NULL)
  {
    tmp = (t_channel *)list->value;
    if (current != NULL && strcmp(tmp->name, current->name) == 0)
    {
      wattron(WIN(w_chans), COLOR_PAIR(5));
      mvwaddstr(WIN(w_chans), 1, i + 1, tmp->name);
      wattroff(WIN(w_chans), COLOR_PAIR(5));
    }
    else
      mvwaddstr(WIN(w_chans), 1, i + 1, tmp->name);
    i += strlen(tmp->name) + 1;
    list = list->next;
  }
  wrefresh(WIN(w_chans));
}
