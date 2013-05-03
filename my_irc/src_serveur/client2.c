/*
** client2.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:32:58 2013 maxime ginters
** Last update Sun Apr 28 22:10:48 2013 maxime ginters
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "client.h"

int		register_client_fd(fd_set *fds)
{
  int		size;
  int		max;
  t_client	*client;

  max = -1;
  size = (int)list_get_size(client_list) - 1;
  while (size >= 0)
  {
    if ((client = (t_client*)GET_AT(client_list, size)) != NULL)
    {
      FD_SET(client->sockfd, fds);
      if (client->sockfd > max)
        max = client->sockfd;
    }
    --size;
  }
  return (max);
}

void		send_to_client(t_client *client, const char *msg, ...)
{

  va_list	ap;
  char		buff[2048];
  int		size;

  va_start(ap, msg);
  size = vsprintf(&buff[5], msg, ap);
  va_end(ap);
  sprintf(buff, "%04d", size);
  buff[4] = ':';
  printf("SEND : [%s] to %s\n", buff, client->name);
  write(client->sockfd, buff, size + 5);
}

int	is_valid_nick(const char *nick)
{
  int	i;

  if (strlen(nick) <= 1)
    return (-1);
  i = 0;
  while (nick[i])
  {
    if (isalnum((int)nick[i]) == 0)
      return (-1);
    ++i;
  }
  return (0);
}

int	is_nick_available(const char *nick)
{
  int		size;
  t_client	*client;

  if (is_valid_nick(nick) != 0)
    return (-2);

  size = (int)list_get_size(client_list) - 1;
  while (size >= 0)
  {
    if ((client = (t_client*)GET_AT(client_list, size)) != NULL)
      if (strcmp(client->name, nick) == 0)
        return (-1);
    --size;
  }
  return (0);
}

t_client	*get_client_by_name(const char *name)
{
  int		size;
  t_client	*client;

  size = (int)list_get_size(client_list) - 1;
  while (size >= 0)
  {
    if ((client = (t_client*)GET_AT(client_list, size)) != NULL)
      if (strcmp(client->name, name) == 0)
        return (client);
    --size;
  }
  return (NULL);
}
