/*
** serveur.h for serveur in /Storage/Epitech/my_ftp/serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 10 14:46:39 2013 maxime ginters
** Last update Sun Apr 14 19:53:42 2013 maxime ginters
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

#include <poll.h>
#include <netinet/in.h>

#define POLL_TIMEOUT 300000

typedef struct
{
  int			sockfd;
  struct sockaddr_in	sock;
  char			pwd[512];
  char			srv_pwd[512];
  char			buffer[4096];
  int			buff_size;
  int			file_fd;
  double		filesize;
  double		received;
  char			send_statut;
  char			filename[512];
}			t_client;

void	socket_loop(int sockfd);
int	create_socket(int port);
void	handle_connect(int sockfd, int newfd, struct sockaddr_in *newsock);
void	client_loop(t_client *client);
void	handle_event(t_client *client, struct pollfd* poll);

#endif /* !SERVEUR_H_ */
