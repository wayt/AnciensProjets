/*
** server.c for src_serveur in /Storage/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 21 14:45:53 2013 maxime ginters
** Last update Sun Apr 28 18:36:15 2013 maxime ginters
*/

#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <time.h>
#include "client.h"
#include "server.h"
#include "channels.h"
#include "commands.h"

int			create_acceptor(int port, t_server *server)
{
  if ((server->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return (-1);
  }
  memset(&server->sock, 0, sizeof(struct sockaddr_in));
  server->sock.sin_family = AF_INET;
  server->sock.sin_port = htons(port);
  server->sock.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(server->sockfd, (struct sockaddr*)&server->sock,
        sizeof(server->sock)) < 0 || listen(server->sockfd, 0) < 0)
  {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    close(server->sockfd);
    return (-1);
  }
  return (0);

}

int	init_fd(fd_set *fd_in, int serverfd)
{
  int	max;

  FD_ZERO(fd_in);
  FD_SET(serverfd, fd_in);
  max = register_client_fd(fd_in);
  if (serverfd > max)
    max = serverfd;
  return (max);
}

void			handle_accept(t_server *server)
{
  int			newfd;
  struct sockaddr_in	newsock;
  socklen_t		socklen;

  memset(&newsock, 0, sizeof(newsock));
  socklen = 0;
  if ((newfd = accept(server->sockfd,
          (struct sockaddr*)&newsock, &socklen)) > 2)
  {
    if (handle_connect(newfd, newsock) != 0)
      close(newfd);
  }
  else
    fprintf(stderr, "Error: %s\n", strerror(errno));
}

void		handle_close(t_client *client)
{
  int		size;
  t_channel	*chan;

  size = (int)list_get_size(channel_list) - 1;
  while (size >= 0)
  {
    if ((chan = (t_channel*)GET_AT(channel_list, size)) != NULL)
      if (is_client_in_channel(client, chan) == 0)
      {
        remove_client_from_channel(client, chan);
        broadcast_to_channel(chan, "PEERRESET:%s:%s:%s lost connection",
            chan->name, client->name, client->name);
      }
    --size;
  }
  close(client->sockfd);
  delete_client(client);
  free(client);
  printf("Client close - new size : %u\n", list_get_size(client_list));
}

int	get_next_command_size(t_client *client)
{
  char	buff[5];

  memset(buff, 0, 5);
  if (safe_memcpy(buff, &client->buff, 4) != 0)
    return (-1);
  return (atoi(buff));
}

