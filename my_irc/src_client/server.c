/*
** server.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:12:41 2013 maxime ginters
** Last update Sun Apr 28 18:27:01 2013 maxime ginters
*/

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"
#include "channels.h"

int	register_servers_fd(t_list list, fd_set *fds)
{
  int		size;
  t_server	*server;
  int		max;

  size = (int)list_get_size(list) - 1;
  max = -1;
  while (size >= 0)
  {
    if ((server = (t_server*)GET_AT(list, size)) != NULL)
    {
      FD_SET(server->sockfd, fds);
      if (server->sockfd > max)
        max = server->sockfd;
    }
    --size;
  }
  return (max);
}

void	remove_server(t_list *list, t_server *server)
{
  int		size;
  t_server	*srv;

  size = (int)list_get_size(*list) - 1;
  while (size >= 0)
  {
    if ((srv = (t_server*)GET_AT(*list, size)) != NULL)
      if (server == srv)
      {
        list_del_elem_at_position(list, (unsigned int)size);
        remove_all_channel(srv);
        free(srv);
        return ;
      }
    --size;
  }
}

#define CONNECT_FAIL(a) { free(a); return (NULL); }

t_server	*connect_to(const char *host, const char *port)
{
  struct hostent	*hostinfo;
  t_server		*server;
  socklen_t		socklen;

  if ((server = malloc(sizeof(t_server))) == NULL)
    return (NULL);
  memset(&server->sock, 0, sizeof(server->sock));
  if ((server->sockfd = socket(AF_INET, SOCK_STREAM, 0)) <= 2)
    CONNECT_FAIL(server);
  if ((hostinfo = gethostbyname(host)) == NULL)
    CONNECT_FAIL(server);
  server->sock.sin_addr = *(struct in_addr*)hostinfo->h_addr;
  server->sock.sin_port = htons(atoi(port));
  server->sock.sin_family = AF_INET;
  server->channel_list = NULL;
  init_buffer(&server->buff);
  server->current = 1;
  socklen = sizeof(struct sockaddr_in);
  if (connect(server->sockfd,
        (const struct sockaddr*)&server->sock, socklen) < 0)
    CONNECT_FAIL(server);
  return (server);
}

void		send_to_server(t_server *server, const char *msg, ...)
{

  va_list	ap;
  char		buff[2048];
  int		size;

  va_start(ap, msg);
  size = vsprintf(&buff[5], msg, ap);
  va_end(ap);
  sprintf(buff, "%04d", size);
  buff[4] = ':';
  write(server->sockfd, buff, size + 5);
}
