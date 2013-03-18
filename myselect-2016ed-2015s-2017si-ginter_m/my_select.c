/*
** my_select.c for MySelect in /home/fest/Epitech/MySelect
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 19 10:58:29 2012 maxime ginters
** Last update Fri Nov 23 19:33:27 2012 maxime ginters
*/

#include "my.h"
#include <fcntl.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "my_select.h"
#include "key.h"

#define TERM_COL	0
#define TERM_ROW	1
#define CURR_COL	2
#define CURR_ROW	3

#define CURSOR_ROW	4
#define CURSOR_COL	5

#define CCURR_ROW coord[CURR_ROW]
#define CCURR_COL coord[CURR_COL]
#define CCURSOR_ROW coord[CURSOR_ROW]
#define CCURSOR_COL coord[CURSOR_COL]

#define ENLARGE ask_enlarge_window

t_list	*list;

void	handle_resize(int num)
{
  print_args();
  signal(SIGWINCH, handle_resize);
}

void		print_args()
{
  int		coord[6];
  t_list	*itr;
  int		max_len;

  max_len = get_max_strlen(list) + 1;
  my_memset(coord, 0, 6 * sizeof(int));
  get_winsize(&coord[TERM_ROW], &coord[TERM_COL]);
  itr = list;
  put_ctrl("cl");
  while (itr)
  {
    goto_pos(coord[CURR_ROW], coord[CURR_COL] * max_len);
    if (itr->focus == 1)
      set_cursor_pos(CCURR_ROW, CCURR_COL, &CCURSOR_ROW, &CCURSOR_COL);
    print_row(itr);
    if (++coord[CURR_ROW] > coord[TERM_ROW])
    {
      coord[CURR_ROW] = 0;
      if ((++coord[CURR_COL] + 1) * max_len > coord[TERM_COL] && ENLARGE())
        return;
    }
    itr = itr->next;
  }
  goto_pos(coord[CURSOR_ROW], coord[CURSOR_COL] * max_len);
}

void			init_term()
{
  struct termios	term;

  if (tcgetattr(0, &term) != 0)
    exit_error("Fail to get input termios\n");
  term.c_lflag &= ~(ICANON | ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &term) != 0)
    exit_error("Fail to set input termios\n");
  signal(SIGWINCH, handle_resize);
}

void	read_input()
{
  int	c;
  int	i;

  c = 0;
  i = 0;
  while (read(0, &c, sizeof(int)) != 0)
  {
    i = 0;
    while (i != -1 && key_functions[i].key != 0)
    {
      if (key_functions[i].key == c)
      {
        (key_functions[i].funct)(&list);
        i = -1;
      }
      else
        ++i;
    }
    if (i != -1)
      (key_functions[i].funct)(&list);
    c = 0;
  }
}

int	main(int ac, char **av)
{
  if (ac < 2)
  {
    my_printf("Invalide count of arguments ... (minimum 1)\n");
    exit(1);
  }
  tgetent(NULL, "xterm");
  list = create_list(ac - 1, av + 1);
  print_args(list);
  init_term();
  read_input();
  free_list(list);
  return (0);
}
