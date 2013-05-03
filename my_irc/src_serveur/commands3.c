/*
** commands3.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 21:29:03 2013 maxime ginters
** Last update Sun Apr 28 22:18:23 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include "channels.h"
#include "commands.h"

void		handle_send_file(char *msg, t_client *client, t_server *server)
{
  char		*dest;
  t_client	*cli;

  (void)server;
  dest = strtok(msg, ":");
  msg = strtok(NULL, "");
  if (!dest || !msg)
    return ;
  if ((cli = get_client_by_name(dest)) != NULL)
    send_to_client(cli, "SENDFILE:%s:%s", client->name, msg);
}

void		handle_accept_file(char *msg, t_client *client, t_server *server)
{
  t_client	*cli;

  (void)server;
  if (!msg)
    return ;
  if ((cli = get_client_by_name(msg)) != NULL)
    send_to_client(cli, "ACCEPTFILE:%s", client->name);
}

void		handle_filename(char *msg, t_client *client, t_server *server)
{
  char		*dest;
  t_client	*cli;

  (void)server;
  dest = strtok(msg, ":");
  msg = strtok(NULL, "");
  if (!dest || !msg)
    return ;
  if ((cli = get_client_by_name(dest)) != NULL)
    send_to_client(cli, "FILENAME:%s:%s", client->name, msg);
}

void	handle_send_abort(char *msg, t_client *client, t_server *server)
{
  char		*dest;
  t_client	*cli;

  (void)server;
  dest = strtok(msg, ":");
  msg = strtok(NULL, "");
  if (!dest || !msg)
    return ;
  if ((cli = get_client_by_name(dest)) != NULL)
    send_to_client(cli, "SENDABORT:%s:%s", client->name, msg);
}

void		handle_file_next(char *msg, t_client *client, t_server *server)
{
   t_client	*cli;

  (void)server;
  if (!msg)
    return ;
  if ((cli = get_client_by_name(msg)) != NULL)
    send_to_client(cli, "FILENEXT:%s", client->name);
}

void		handle_send_data(char *msg, t_client *client, t_server *server)
{
  t_client	*cli;
  char		*dest;
  char		*ssize;
  int		size;
  char		buff[1024];

  (void)server;
  dest = strtok(msg, ":");
  ssize = strtok(NULL, ":");
  msg = strtok(NULL, "");
  if (!dest || !ssize || !msg)
    return ;
  if ((cli = get_client_by_name(msg)) == NULL)
    return ;
  size = sprintf(&buff[5], "SENDDATA:%s:%03d:", client->name, atoi(ssize));
  memcpy(&buff[5 + size], msg, atoi(ssize));
  size += atoi(ssize);
  sprintf(buff, "%04d:", size);
  buff[5] = 'S';
  write(cli->sockfd, buff, size);
}

void		handle_send_end(char *msg, t_client *client, t_server *server)
{
  t_client	*cli;

  (void)server;
  if (!msg)
    return ;
  if ((cli = get_client_by_name(msg)) != NULL)
    send_to_client(cli, "SENDEND:%s", client->name);
}

