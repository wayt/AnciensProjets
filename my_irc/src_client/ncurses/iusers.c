/*
** iusers.c for  in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 17:16:35 2013 fabien casters
** Last update Sun Apr 28 16:41:43 2013 fabien casters
*/

#include "iusers.h"

void		clear_users(t_interface *in)
{
  int		i;

  i = 18;
  while (i > 0)
  {
    mvwprintw(WIN(w_users), i, 1, "%*s", 18, " ");
    --i;
  }
}

void		refresh_users(t_interface *in, t_list list)
{
  char		*tmp;
  int		i;

  i = 1;
  clear_users(in);
  while (list != NULL)
  {
    tmp = (char *)list->value;
    wattron(WIN(w_users), COLOR_PAIR((tmp[0] % 5) + 1));
    mvwaddstr(WIN(w_users), i, 2, tmp);
    wattroff(WIN(w_users), COLOR_PAIR((tmp[0] % 5) + 1));
    i++;
    list = list->next;
  }
  wrefresh(WIN(w_users));
}
