/*
** handle_down.c for key_functions in /home/fest/Epitech/MySelect/key_functions
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Nov 21 17:12:52 2012 maxime ginters
** Last update Fri Nov 23 16:06:10 2012 maxime ginters
*/

#include "key.h"
#include "my_select.h"
#include "my.h"
#include "list.h"

void	handle_down(t_list **list)
{
  down_focus(*list);
  print_args(*list);
}
