/*
** server.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:00:09 2013 maxime ginters
** Last update Fri Apr 26 12:00:07 2013 maxime ginters
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include "list.h"
#include "buffer.h"

#define NICK_BUFFER_SIZE  128

typedef struct
{
  int			sockfd;
  struct sockaddr_in	sock;
  t_list		channel_list;
  char			nickname[NICK_BUFFER_SIZE];
  t_buffer		buff;
  char			current;
}			t_server;

int		register_servers_fd(t_list list, fd_set *fds);
void		remove_server(t_list *list, t_server* server);
t_server	*connect_to(const char *host, const char *port);
void		send_to_server(t_server *server, const char *msg, ...);

#endif /* !SERVER_H_ */
