/*
** interface.c for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 14:17:40 2013 fabien casters
** Last update Sun Apr 28 16:38:01 2013 fabien casters
*/

#include <stdio.h>
#include <string.h>
#include <curses.h>
#include "iinput.h"
#include "interface.h"

int		error_str(char *str)
{
  fprintf(stderr, str);
  return (0);
}

void		refresh_interface(t_interface *in)
{
  wrefresh(WIN(w_root));
}

int		create_interface(t_interface *in)
{
  if ((WIN(w_root) = initscr()) == NULL)
    return (error_str("initscr fail !"));
  if ((WIN(w_chans) = subwin(WIN(w_root), 3, 80, 0, 0)) == NULL)
    return (error_str("subwin chans fail !"));
  wborder(WIN(w_chans), 0, 0, 0, 0, 0, 0, 0, 0);
  if ((WIN(w_users) = subwin(WIN(w_root), 20, 20, 3, 60)) == NULL)
    return (error_str("subwin users fail !"));
  wborder(WIN(w_users), 0, 0, 0, 0, 0, 0, 0, 0);
  if ((WIN(w_mesgs) = subwin(WIN(w_root), 17, 60, 3, 0)) == NULL)
    return (error_str("subwin mesgs fail !"));
  wborder(WIN(w_mesgs), 0, 0, 0, 0, 0, 0, 0, 0);
  if ((WIN(w_input) = subwin(WIN(w_root), 3, 60, 20, 0)) == NULL)
    return (error_str("subwin input fail !"));
  wborder(WIN(w_input), 0, 0, 0, 0, 0, 0, 0, 0);
  curs_set(0);
  noecho();
  start_color();
  cbreak();
  keypad(WIN(w_root), TRUE);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  refresh_interface(in);
  return (1);
}

int		input_interface(t_interface *in, char *dst)
{
  static char	buf[4096] = {0};
  static int	index = 0;
  int		key;

  key = wgetch(WIN(w_root));
  if ( ' ' <= key && key <= '~' && index < 4096)
    return (key_insert(buf, key, &index, in));
  else if ((key == 263 || key == 127) && index > 0)
    return (key_delete(buf, &index, in));
  else if (key == '\n' && index > 0)
    return (key_send(buf, dst, &index, in));
  else if (key == KEY_LEFT)
  {
    memcpy(dst, "/window left\0", 13);
    return (1);
  }
  else if (key == KEY_RIGHT)
  {
    memcpy(dst, "/window right\0", 14);
    return (1);
  }
  return (0);
}

int		destroy_interface(t_interface *in)
{
  (void)in;
  endwin();
  return (1);
}
