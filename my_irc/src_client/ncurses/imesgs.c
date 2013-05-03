/*
** imesgs.c for  in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 18:01:16 2013 fabien casters
** Last update Sun Apr 28 16:39:44 2013 fabien casters
*/

#include <string.h>
#include <curses.h>
#include "imesgs.h"
#include "channels.h"

void		clear_mesgs(t_interface *in)
{
  int		i;

  i = 15;
  while (i > 0)
  {
    mvwprintw(WIN(w_mesgs), i, 1, "%*s", 58, " ");
    --i;
  }
}

void		write_pseudo(t_interface *in, char *pseudo, int i)
{
  wattron(WIN(w_mesgs), COLOR_PAIR((pseudo[0] % 5) + 1));
  mvwprintw(WIN(w_mesgs), i, 1, "--> %.*s :", 58, pseudo);
  wattroff(WIN(w_mesgs), COLOR_PAIR((pseudo[0] % 5) + 1));
}

void		refresh_mesgs(t_interface *in, t_list list)
{
  t_message	*tmp;
  int		i;
  int		j;

  i = 15;
  clear_mesgs(in);
  while (list != NULL)
  {
    tmp = (t_message *)list->value;
    j = (strlen(tmp->msg) / 58) + ((strlen(tmp->msg) % 58 != 0) ? 1 : 0) - 1;
    while (j >= 0 && i > 0)
    {
      mvwprintw(WIN(w_mesgs), i, 1, "%.*s", 58, (tmp->msg) + (j * 58));
      i--;
      if (j == 0 && i > 0)
      {
        write_pseudo(in, tmp->sender, i);
        i--;
      }
      j--;
    }
    list = list->next;
  }
  wrefresh(WIN(w_mesgs));
}
