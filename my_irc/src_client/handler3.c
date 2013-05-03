/*
** handler3.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 19:37:52 2013 maxime ginters
** Last update Sun Apr 28 22:20:43 2013 maxime ginters
*/

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "file.h"
#include "master.h"
#include "handler.h"
#include "channels.h"

void		handle_send_file(char *cmd, t_server *server)
{
  char		*from;
  t_channel	*chan;
  char		buff[512];

  from = strtok(cmd, ":");
  cmd = strtok(NULL, "");
  if (!from || !cmd)
    return ;
  if ((chan = find_channel_by_name(server, from)) == NULL)
    if ((chan = create_channel(from, 0, server)) == NULL)
      return ;
  sprintf(buff, "New file (%s) from %s, to accept enter : /accept_file %s",
      cmd, from, from);
  push_msg_to_channel(chan, "@client", buff);
}

void	handle_accept_file(char *cmd, t_server *server)
{
  if (!send_file)
    return ;
  if (strcmp(send_file->peer, cmd) != 0)
    return ;
  send_file->status = 1;
  send_to_server(server, "FILENAME:%s:%s",
      send_file->peer, send_file->filename);
}

void	handle_filename(char *cmd, t_server *server)
{
  char	*peer;

  peer = strtok(cmd, ":");
  cmd = strtok(NULL, "");
  if (!send_file || strcmp(send_file->peer, peer) != 0)
    return ;
  strncpy(send_file->filename, cmd, FILENAME_BUFFER_SIZE);
  if ((send_file->fd = open(cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644)) <= 2)
  {
    push_msg_to_channel(accueil, "@client", "Fail to create local file");
    send_to_server(server, "SENDABORT:%s:Remote fail to create file", peer);
    free(send_file);
    send_file = NULL;
    return ;
  }
  send_file->status = 1;
  send_to_server(server, "FILENEXT:%s", peer);
}

void		handle_send_abort(char *cmd, t_server *server)
{
  char		*peer;
  t_channel	*chan;

  peer = strtok(cmd, ":");
  cmd = strtok(NULL, "");
  if (!send_file || strcmp(send_file->peer, peer) != 0)
    return ;
  if ((chan = find_channel_by_name(server, peer)) == NULL)
    if ((chan = create_channel(peer, 0, server)) == NULL)
      return ;
  push_msg_to_channel(chan, "@client", cmd);
  close(send_file->fd);
  free(send_file);
  send_file = NULL;
}

void		handle_file_next(char *cmd, t_server *server)
{
  char		buff[2][1024];
  int		size[2];

  if (!send_file || strcmp(send_file->peer, cmd) != 0 ||
      send_file->status != 1)
    return ;
  size[0] = sprintf(&buff[0][5], "SENDDATA:%s:", cmd);
  if ((size[1] = read(send_file->fd, buff[1], 512)) <= 0)
  {
    close(send_file->fd);
    free(send_file);
    send_file = NULL;
    send_to_server(server, "SENDEND:%s", cmd);
    return ;
  }
  sprintf(&buff[0][size[0] + 5], "%03d:", size[1]);
  memcpy(&buff[0][size[0] + 5 + 4], buff[1], size[1]);
  sprintf(buff[0], "%04d:", size[0] + 5 + 4 + size[1]);
  buff[0][5] = 'S';
  write(server->sockfd, buff[0], size[0] + 5 + 4 + size[1]);
}

void	handle_send_data(char *cmd, t_server *server)
{
  char	*peer;
  char	*ssize;

  peer = strtok(cmd, ":");
  ssize = strtok(NULL, ":");
  cmd = strtok(NULL, "");

  if (!send_file || strcmp(send_file->peer, peer) != 0 ||
      send_file->status != 1 || !ssize || !cmd)
    return ;
  write(send_file->fd, cmd, atoi(ssize));
  send_to_server(server, "FILENEXT:%s", peer);
}

void		handle_send_end(char *cmd, t_server *server)
{
  char		*peer;
  t_channel	*chan;

  peer = strtok(cmd, ":");
  if (!send_file || strcmp(send_file->peer, peer) != 0 ||
      send_file->status != 1)
    return ;
  close(send_file->fd);
  free(send_file);
  send_file = NULL;
  if ((chan = find_channel_by_name(server, peer)) == NULL)
    if ((chan = create_channel(peer, 0, server)) == NULL)
      return ;
  push_msg_to_channel(chan, "@client", "File finished");
}
