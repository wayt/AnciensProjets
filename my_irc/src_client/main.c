/*
** main.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 14:53:46 2013 maxime ginters
** Last update Thu Apr 25 15:36:50 2013 maxime ginters
*/

#include <stdio.h>
#include "master.h"

int	usage()
{
  printf("usage: ./client\n");
  return (1);
}

int	main(int ac, char **av)
{
  (void)av;
  if (ac < 1)
    return (usage());
  return (run());
}
