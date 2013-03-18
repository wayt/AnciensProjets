/*
** handle_enter.c for key_functions in /home/fest/Epitech/MySelect/key_functions
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Nov 21 17:16:33 2012 maxime ginters
** Last update Fri Nov 23 19:08:30 2012 maxime ginters
*/

#include "my.h"
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "key.h"
#include "list.h"
#include "my_select.h"

void	handle_enter(t_list **list)
{
  t_list	*start;
  t_list	*itr;
  char	first;

  put_ctrl("cl");
  start = *list;
  itr = *list;
  first = 1;
  while (itr)
  {
    if (itr->selected == 1)
    {
      if (first != 1)
        write(1, " ", 1);
      first = 0;
      my_putstr(itr->str);
    }
    itr = itr->next;
  }
  free_list(start);
  exit(0);
}
