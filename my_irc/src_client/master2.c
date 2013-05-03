/*
** master2.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:43:47 2013 maxime ginters
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

void		process_fd(fd_set *fds)
{
  int		size;
  t_server	*server;

  if (FD_ISSET(0, fds))
    handle_write();
  size = (int)list_get_size(server_list) - 1;
  while (size >= 0)
  {
    if ((server = (t_server*)GET_AT(server_list, size)) != NULL)
      if (FD_ISSET(server->sockfd, fds))
        handle_input(server);
    --size;
  }
}

int		run()
{
  fd_set	fds;
  int		max_fd;

  create_interface(&interface);
  running = true;
  accueil = NULL;
  accueil = create_channel("Accueil", 1, NULL);
  set_current_channel(accueil);
  while (running)
  {
    max_fd = init_fd(&fds);
    if (select(max_fd + 1, &fds, NULL, NULL, NULL) > 0)
      process_fd(&fds);
  }
  destroy_interface(&interface);
  return (0);
}

t_server	*get_current_server()
{
  t_server	*server;
  int		size;

  size = (int)list_get_size(server_list) - 1;
  while (size >= 0)
  {
    if ((server = GET_AT(server_list, size)) != NULL)
      if (server->current == 1)
        return (server);
    --size;
  }
  return (NULL);
}

int	get_currents_index(int *srv, int *chn)
{
  t_server	*server;
  int		size;
  int		size2;
  t_channel	*chan;

  size = (int)list_get_size(server_list);
  while (--size >= 0)
    if ((server = GET_AT(server_list, size)) != NULL)
      if (server->current == 1)
      {
        *srv = size;
        size2 = (int)list_get_size(server->channel_list);
        while (--size2 >= 0)
          if ((chan = (t_channel*)GET_AT(server->channel_list, size2)) != NULL)
            if (chan->current == 1)
            {
              *chn = size2;
              return (0);
            }
      }
  return (-1);
}

t_channel	*get_current_channel()
{
  t_server	*server;
  t_channel	*chan;

  if ((server = get_current_server()) != NULL)
    if ((chan = find_current_channel(server)) != NULL)
      return (chan);
  return (NULL);
}

