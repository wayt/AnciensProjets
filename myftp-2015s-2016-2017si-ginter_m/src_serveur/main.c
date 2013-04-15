/*
** main.c for my_ftp in /Storage/Epitech/my_ftp
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 10 14:39:25 2013 maxime ginters
** Last update Thu Apr 11 14:09:21 2013 maxime ginters
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "serveur.h"

void	print_usage()
{
  printf("Usage : ./serveur port\n");
}

int	main(int ac, char **av)
{
  int	sockfd;

  if (ac < 2 || strcmp(av[1], "-h") == 0)
  {
    print_usage();
    return 0;
  }
  if ((sockfd = create_socket(atoi(av[1]))) < 0)
    return (1);

  socket_loop(sockfd);

  close(sockfd);
  return (0);
}
