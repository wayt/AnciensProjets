/*
** handle_up.c for key_functions in /home/fest/Epitech/MySelect/key_functions
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Nov 21 16:57:31 2012 maxime ginters
** Last update Fri Nov 23 16:09:00 2012 maxime ginters
*/

#include "my.h"
#include "my_select.h"
#include "list.h"
#include "key.h"

void	handle_up(t_list **list)
{
  up_focus(*list);
  print_args(*list);
}
