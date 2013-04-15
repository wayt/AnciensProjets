/*
** serveur.c for serveur in /Storage/Epitech/my_ftp/serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 10 14:47:04 2013 maxime ginters
** Last update Sun Apr 14 19:40:51 2013 maxime ginters
*/

#define _GNU_SOURCE

#include <sys/socket.h>
#include <netinet/ip.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "serveur.h"
#include "commands.h"

void			socket_loop(int sockfd)
{
  int			newfd;
  struct sockaddr_in	newsock;
  socklen_t		sock_size;

  sock_size = sizeof(struct sockaddr_in);
  while (42 == 42)
  {
    memset(&newsock, 0, sizeof(newsock));
    newfd = accept(sockfd, (struct sockaddr*)&newsock, &sock_size);
    if (newfd > 2)
      handle_connect(sockfd, newfd, &newsock);
    else
    {
      fprintf(stderr, "Error: %s\n", strerror(errno));
      close(newfd);
    }
  }
}

int			create_socket(int port)
{
  int			sockfd;
  struct sockaddr_in	sock;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return (-1);
  }
  memset(&sock, 0, sizeof(struct sockaddr_in));
  sock.sin_family = AF_INET;
  sock.sin_port = htons(port);
  sock.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(sockfd, (struct sockaddr*)&sock, sizeof(struct sockaddr_in)) < 0 ||
      listen(sockfd, 0) < 0)
  {
    printf("Error: %s\n", strerror(errno));
    close(sockfd);
    return (-1);
  }
  return (sockfd);
}

void	handle_connect(int sockfd, int newfd, struct sockaddr_in *newsock)
{
  t_client	client;

  printf("New connection from %s\n", inet_ntoa(newsock->sin_addr));
  client.sockfd = newfd;
  client.sock = *newsock;
  memset(client.pwd, 0, 512);
  getcwd(client.pwd, 512);
  memset(client.srv_pwd, 0, 512);
  getcwd(client.srv_pwd, 512);
  memset(client.buffer, 0, 4096);
  client.buff_size = 0;
  client.file_fd = -1;
  client.send_statut = -1;
  if (fork() == 0)
  {
    close(sockfd);
    client_loop(&client);
  }
  else
    close(newfd);
}

void		client_loop(t_client *client)
{
  struct pollfd	fds;
  int		ret;

  fds.fd = client->sockfd;
  fds.events = POLLIN | POLLRDHUP;
  while (42 == 42)
  {
    fds.revents = 0;
    ret = poll(&fds, 1, POLL_TIMEOUT);
    if (ret > 0)
      handle_event(client, &fds);
    else
    {
      fprintf(stderr, "Error: %s\n", ret == 0 ?
          "\rpeer connection timeout" : strerror(errno));
      close(client->sockfd);
      exit(0);
    }
  }
}

void	handle_event(t_client *client, struct pollfd* poll)
{
  if (poll->revents & POLLRDHUP)
  {
    fprintf(stderr, "Remote host closed socket\n");
    close(client->sockfd);
    exit(0);
  }
  if (poll->revents & POLLIN)
  {
    client->buff_size += read(client->sockfd, client->buffer,
        4096 - client->buff_size);
    parse_buffer(client);
  }
}
