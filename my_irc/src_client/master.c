/*
** master.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:04:31 2013 maxime ginters
** Last update Sun Apr 28 18:44:06 2013 maxime ginters
*/

#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "handler.h"
#include "commands.h"
#include "master.h"

t_list		server_list;
t_interface	interface;
bool		running;
t_channel	*accueil;

int	init_fd(fd_set *fds)
{
  int	max;

  FD_ZERO(fds);
  FD_SET(0, fds);
  max = register_servers_fd(server_list, fds);
  if (0 > max)
    return (0);
  return (max);
}

void	handle_close(t_server *server)
{
  char	buff[128];

  sprintf(buff, "Lost connection to server %s",
      inet_ntoa(server->sock.sin_addr));
  push_msg_to_channel(accueil, "@client", buff);
  close(server->sockfd);
  remove_server(&server_list, server);
  set_current_channel(accueil);
}

void	handle_input(t_server *server)
{
  int	rd_size;

  if ((rd_size = read(server->sockfd, BUFF_WR(&server->buff),
          get_wr_size(&server->buff))) <= 0)
  {
    handle_close(server);
    return ;
  }
  move_wrindex(&server->buff, rd_size);
  while (process_handler(server) == 0);
}

void	handle_write()
{
  char	buff[4096];

  memset(buff, 0, 4096);
  if (input_interface(&interface, buff) == 0)
    return ;
  parse_command(buff);
}

