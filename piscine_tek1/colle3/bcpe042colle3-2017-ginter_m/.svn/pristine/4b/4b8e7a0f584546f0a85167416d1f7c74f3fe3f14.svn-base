/*
** main.c for bcpe042colle3-2017-ginter_m in /home/fest/Epitech/bcpe042colle3-2017-ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 27 16:29:41 2012 maxime ginters
** Last update Sat Oct 27 23:24:40 2012 maxime ginters
*/

#include <unistd.h>
#include "what_is_this_glue.h"
#include "utils.h"

int	main(int ac, char *av[])
{
  char	buff[4096 + 1];
  int	len;

  len = read(0, buff, 4096);
  if (len > 0)
  {
    buff[len] = 0;
    what_is_this_glue(buff);
  }
  return (0);
}
