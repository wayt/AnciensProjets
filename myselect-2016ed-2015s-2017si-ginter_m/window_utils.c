/*
** window_utils.c for MySelect in /home/fest/Epitech/MySelect
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 23 19:08:41 2012 maxime ginters
** Last update Fri Nov 23 19:24:16 2012 maxime ginters
*/

#include "my.h"
#include "my_select.h"

void	print_row(t_list *elem)
{
  if (elem->focus == 1)
    put_ctrl("us");
  if (elem->selected == 1)
    put_ctrl("mr");
  write_tty(elem->str);
  put_ctrl("me");
}

int	ask_enlarge_window()
{
  put_ctrl("cl");
  write_tty("Error : window to small, please grow !");
  return (1);
}

void	set_cursor_pos(int row, int col, int *p_row, int *p_col)
{
  *p_row = row;
  *p_col = col;
}
