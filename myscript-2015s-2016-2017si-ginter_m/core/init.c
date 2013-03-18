/*
** init.c for core in /Storage/Epitech/my_script/core
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Feb 28 14:52:14 2013 maxime ginters
** Last update Thu Feb 28 14:56:57 2013 maxime ginters
*/

#include "core.h"

void	remove_block(int fd1, int fd2)
{
  int	flags;

  flags = 0;
  if (fcntl(fd1, F_GETFL, &flags) == -1)
    xperror();
  if (fcntl(fd1, F_SETFL, flags | O_NONBLOCK) == -1)
    xperror();
  flags = 0;
  if (fcntl(fd2, F_GETFL, &flags) == -1)
    xperror();
  if (fcntl(fd2, F_SETFL, flags | O_NONBLOCK) == -1)
    xperror();
}

void	init_term(struct termios* term)
{
  if (tcgetattr(0, term) == -1)
    xperror();
  term->c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
  if (tcsetattr(0, TCSANOW, term) == -1)
    xperror();
}

void	restore_term(struct termios* term)
{
  term->c_lflag |= ECHO | ICANON | IEXTEN | ISIG;
  if (tcsetattr(0, TCSANOW, term) == -1)
    xperror();
}
