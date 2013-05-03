/*
** main.c for src_serveur in /Storage/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 21 14:48:26 2013 maxime ginters
** Last update Sun Apr 21 15:10:01 2013 maxime ginters
*/

#include "server.h"

int	usage()
{
  fprintf(stderr, "Usage: ./serveur _port_\n");
  return (1);
}

int	main(int ac, char **av)
{
  int	port;

  if (ac < 2)
    return (usage());
  port = atoi(av[1]);
  return (run(port));
}
