/*
** server.h for src_serveur in /Storage/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 21 14:45:53 2013 maxime ginters
** Last update Sun Apr 28 18:38:02 2013 maxime ginters
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"

typedef struct
{
  int			sockfd;
  struct sockaddr_in	sock;
}			t_server;

int	run(int port);
int	handle_connect(int newfd, struct sockaddr_in sock);
int	create_acceptor(int port, t_server *server);
int	init_fd(fd_set *fd_in, int serverfd);
void	handle_accept(t_server *server);
void	handle_close(t_client *client);
int	get_next_command_size(t_client *client);

#endif /* !SERVER_H_ */
