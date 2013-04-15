/*
** client.h for client in /Storage/Epitech/my_ftp/client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 16:44:47 2013 maxime ginters
** Last update Sat Apr 13 17:17:43 2013 maxime ginters
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#define KEEP_ALIVE_PING_INTERVAL 30

typedef struct
{
  int		sockfd;
  char		wait_data;
  int		file_fd;
  double	filesize;
  double	received;
  char		buffer[4096];
  int		buff_size;
  char		wait_pong;
  char		send_statut;
  char		filename[512];
}		t_client;

int	connect_to(const char *host, const char *port);
void	client_loop(int sockfd);

#endif /* !CLIENT_H_ */
