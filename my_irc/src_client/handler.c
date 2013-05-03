/*
** handler.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 14:09:29 2013 maxime ginters
** Last update Sun Apr 28 21:19:11 2013 maxime ginters
*/

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "master.h"
#include "handler.h"
#include "channels.h"

t_handler	handlers[] = {
  {"MSG:", handle_msg},
  {"NICK:", handle_nick},
  {"SRVMSG:", handle_server_msg},
  {"PEERRESET:", handle_peer_lost},
  {"PEERLEAVE:", handle_peer_lost},
  {"PEERJOIN:", handle_peer_join},
  {"PEERNICK:", handle_peer_nick},
  {"PEERADD:", handle_peer_add},
  {"SENDFILE:", handle_send_file},
  {"ACCEPTFILE:", handle_accept_file},
  {"FILENAME:", handle_filename},
  {"SENDABORT:", handle_send_abort},
  {"FILENEXT:", handle_file_next},
  {"SENDDATA:", handle_send_data},
  {"SENDEND:", handle_send_end},
  {NULL, NULL}
};

int	get_next_command_size(t_server *server)
{
  char	buff[5];

  memset(buff, 0, 5);
  if (safe_memcpy(buff, &server->buff, 4) != 0)
    return (-1);
  return (atoi(buff));
}

int	process_handler(t_server *server)
{
  char	buff[BUFFER_SIZE];
  int	size;

  if ((size = get_next_command_size(server)) < 0)
    return (-1);
  if (move_rdindex(&server->buff, 5, size) != 0)
    return (-1);
  safe_memcpy(buff, &server->buff, size);
  buff[size] = 0;
  parse_handler(buff, server);
  move_rdindex(&server->buff, size, 0);
  return (0);
}

void	parse_handler(char *msg, t_server *server)
{
  int	i;
  int	size;

  i = 0;
  while (handlers[i].cmd)
  {
    size = strlen(handlers[i].cmd);
    if (strncmp(msg, handlers[i].cmd, size) == 0)
    {
      (handlers[i].func)(msg + size, server);
      return ;
    }
    ++i;
  }
}

void		handle_msg(char *cmd, t_server *server)
{
  char		*chname;
  char		*sender;
  t_channel	*chan;

  (void)server;
  chname = strtok(cmd, ":");
  sender = strtok(NULL, ":");
  cmd = strtok(NULL, "");
  if (!chname || !sender || !cmd)
    return ;
  if ((chan = find_channel_by_name(server, chname)) == NULL)
  {
    if (chname[0] != '#')
    {
      if ((chan = create_channel(sender, 0, server)) == NULL)
        return ;
    }
    else
      return ;
  }
  push_msg_to_channel(chan, sender, cmd);
}

void	handle_nick(char *cmd, t_server *server)
{
  char	buff[512];

  if (!cmd || strlen(cmd) <= 1)
    return ;
  strncpy(server->nickname, cmd, NICK_BUFFER_SIZE);
  sprintf(buff, "New nick on server %s : %s",
      inet_ntoa(server->sock.sin_addr), server->nickname);
  push_msg_to_channel(accueil, "@client", buff);
}
