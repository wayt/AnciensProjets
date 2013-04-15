/*
** client.c for client in /Storage/Epitech/my_ftp/client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 16:44:21 2013 maxime ginters
** Last update Sun Apr 14 19:25:01 2013 maxime ginters
*/

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "commands.h"

void	throw_error()
{
  fprintf (stderr, "Error: %s\n", strerror(errno));
  exit(1);
}

int			connect_to(const char *host, const char *port)
{
  struct hostent	*hostinfo;
  struct sockaddr_in	sock;
  int			sockfd;
  socklen_t		sock_size;

  sock_size = sizeof(struct sockaddr_in);
  memset(&sock, 0, sizeof(sock));
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    throw_error();
  if ((hostinfo = gethostbyname(host)) == NULL)
  {
    fprintf (stderr, "Unknown host %s.\n", host);
    exit(1);
  }
  sock.sin_addr = *(struct in_addr*)hostinfo->h_addr;
  sock.sin_port = htons(atoi(port));
  sock.sin_family = AF_INET;
  if (connect(sockfd, (const struct sockaddr*)&sock, sock_size) < 0)
    throw_error();
  return (sockfd);
}

void	ping_server(t_client *client)
{
  if (client->wait_pong == 1)
  {
    fprintf(stderr, "Error: server connection timedout ...\n");
    close(client->sockfd);
    exit(1);
  }
  dprintf(client->sockfd, "PING%s", TCP_SEPARATOR);
  client->wait_pong = 1;
}

void	process_fd(t_client* client, fd_set *fd_in)
{
  int	size;
  char	buff[4096];

  memset(buff, 0, 4096);
  if (FD_ISSET(0, fd_in))
  {
    if ((size = read(0, buff, 4096)) > 0)
      buff[size - 1] = 0;
    if (client->wait_data == 0)
      handle_command(client, buff, size);
  }
  else if (FD_ISSET(client->sockfd, fd_in))
  {
    size = read(client->sockfd, &client->buffer[client->buff_size],
        4096 - client->buff_size);
    if (size <= 0)
    {
      fprintf(stderr, "Server closed connection...\n");
      exit(0);
    }
    client->buff_size += size;
    handle_receiv(client);
  }
  else
    ping_server(client);
}

void			client_loop(int sockfd)
{
  fd_set		fd_in;
  struct timeval	tv;
  t_client		client;

  client.sockfd = sockfd;
  client.wait_data = 0;
  client.file_fd = -1;
  memset(client.buffer, 0, 4096);
  client.buff_size = 0;
  client.wait_pong = 0;
  tv.tv_usec = 0;
  handle_prompt(&client, NULL, 0);
  while (42 == 42)
  {
    FD_ZERO(&fd_in);
    if (client.wait_data == 0)
      FD_SET(0, &fd_in);
    FD_SET(sockfd, &fd_in);
    tv.tv_sec = KEEP_ALIVE_PING_INTERVAL;
    select(sockfd + 1, &fd_in, NULL, NULL, &tv);
    process_fd(&client, &fd_in);
  }
}
