/*
** safe_close.c for libmy in /home/fest/Epitech/Minishell2/libmy
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Nov 29 13:47:43 2012 maxime ginters
** Last update Fri Nov 30 16:59:57 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	safe_close(int fd)
{
  if (fd <= 2)
    return;
  close(fd);
}

void	safe_free(void *ptr)
{
  if (!ptr)
    return;
  free(ptr);
}
