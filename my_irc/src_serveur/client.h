/*
** client.h for src_serveur in /Storage/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 22 11:36:22 2013 maxime ginters
** Last update Sat Apr 27 15:56:55 2013 maxime ginters
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdlib.h>
#include <arpa/inet.h>
#include "list.h"
#include "buffer.h"

#define CLIENT_NAME_BUFFER_SIZE 128

typedef struct
{
  int			sockfd;
  struct sockaddr_in	sock;
  t_buffer		buff;
  char			name[CLIENT_NAME_BUFFER_SIZE];
}			t_client;

extern t_list	client_list;

void		delete_client(t_client *client);
int		register_client_fd(fd_set *fds);
void		send_to_client(t_client *client, const char *msg, ...);
int		is_valid_nick(const char *nick);
int		is_nick_available(const char *nick);
t_client	*get_client_by_name(const char *name);

#endif /* !CLIENT_H_ */
