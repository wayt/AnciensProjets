/*
** server2.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:35:22 2013 maxime ginters
** Last update Sun Apr 28 18:36:12 2013 maxime ginters
*/

#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <time.h>
#include "client.h"
#include "server.h"
#include "channels.h"
#include "commands.h"

int	process_commands(t_server *server, t_client *client)
{
  char	buff[BUFFER_SIZE];
  int	size;

  (void)server;
  if ((size = get_next_command_size(client)) < 0)
     return (-1);
  if (move_rdindex(&client->buff, 5, size) != 0)
     return (-1);
  safe_memcpy(buff, &client->buff, size);
  buff[size] = 0;
  parse_command(buff, client, server);
  move_rdindex(&client->buff, size, 0);
  return (0);
}

void	handle_input(t_server *server, t_client *client)
{
  int	rd_size;

  (void)server;
  if ((rd_size = read(client->sockfd, BUFF_WR(&client->buff),
          get_wr_size(&client->buff))) <= 0)
  {
    handle_close(client);
    return ;
  }
  move_wrindex(&client->buff, rd_size);
  while (process_commands(server, client) == 0);
}

void		process_fd(t_server *server, fd_set *fds)
{
  int		size;
  t_client	*client;

  if (FD_ISSET(server->sockfd, fds))
    handle_accept(server);
  size = (int)list_get_size(client_list) - 1;
  while (size >= 0)
  {
    client = (t_client*)GET_AT(client_list, size);
    if (!client)
      fprintf(stderr, "Error: client NULL at index %d\n", size);
    else if (FD_ISSET(client->sockfd, fds))
      handle_input(server, client);
    --size;
  }
}

int			run(int port)
{
  int			max_fd;
  fd_set		fd_in;
  t_server		server;

  srand(time(NULL));
  if (create_acceptor(port, &server) != 0)
    return (1);
  while (42 == 42)
  {
    max_fd = init_fd(&fd_in, server.sockfd);
    if (select(max_fd + 1, &fd_in, NULL, NULL, NULL) > 0)
      process_fd(&server, &fd_in);
  }
  return (0);
}

int	handle_connect(int fd, struct sockaddr_in sock)
{
  t_client* client;

  if ((client = malloc(sizeof(t_client))) == NULL)
  {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return (-1);
  }
  client->sockfd = fd;
  client->sock = sock;
  init_buffer(&client->buff);
  memset(client->name, 0, CLIENT_NAME_BUFFER_SIZE);
  while (is_nick_available(client->name) != 0)
    sprintf(client->name, "Unknow%d", rand() % 98654);
  PUSH_BACK(&client_list, client);
  send_to_client(client, "NICK:%s", client->name);
  printf("New client - new size : %u\n", list_get_size(client_list));
  return (0);
}
