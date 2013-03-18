/*
** utils.c for MySelect in /home/fest/Epitech/MySelect
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Nov 22 13:42:05 2012 maxime ginters
** Last update Fri Nov 23 20:00:50 2012 maxime ginters
*/

#include "my.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <curses.h>
#include <term.h>
#include <fcntl.h>

void	get_winsize(int *row, int *col)
{
  struct winsize	win;
  int	fd;

  fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
  if (fd == -1)
    exit_error("Fail to open /dev/tty (O_RDONLY | O_NONBLOCK)...\n");

  if (ioctl(fd, TIOCGWINSZ, &win) == -1)
    exit_error("Error while getting window size...\n");
  *row = (int)win.ws_row;
  *col = (int)win.ws_col;
  close(fd);
}

int	put_tty(int c)
{
  int	fd;

  fd = open("/dev/tty", O_WRONLY);
  if (fd == -1)
    exit_error("Fail to open /dev/tty...\n");
  write(fd, &c, sizeof(int));
  close(fd);
}

void	goto_pos(int row, int col)
{
  char	*str;

  str = tgetstr("cm", NULL);
  tputs(tgoto(str, col, row), 1, put_tty);
}

void	put_ctrl(char *str)
{
  tputs(tgetstr(str, NULL), 1, put_tty);
}

void	write_tty(char *str)
{
  int	fd;
  int	len;

  fd = open("/dev/tty", O_WRONLY);
  if (fd == -1)
    exit_error("Fail to open /dev/tty...\n");
  len = my_strlen(str);
  write(fd, str, len);
  close(fd);
}
