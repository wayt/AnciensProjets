/*
** main.c for client in /Storage/Epitech/my_ftp/client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 16:40:49 2013 maxime ginters
** Last update Thu Apr 11 17:16:14 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void	print_usage()
{
  printf("Usage : ./client machine port\n");
  exit(1);
}

int	main(int ac, char **av)
{
  int	sockfd;

  if (ac < 3)
    print_usage();
  sockfd = connect_to(av[1], av[2]);
  printf("sockfd : %d\n", sockfd);
  client_loop(sockfd);
  printf("Bye bye !\n");
  return (0);
}
