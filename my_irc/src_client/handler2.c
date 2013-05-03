/*
** handler2.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:42:51 2013 maxime ginters
** Last update Sun Apr 28 18:43:16 2013 maxime ginters
*/

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "master.h"
#include "handler.h"
#include "channels.h"

void		handle_server_msg(char *cmd, t_server *server)
{
  t_channel	*chan;

  if ((chan = find_current_channel(server)) != NULL)
    push_msg_to_channel(chan, "@server", cmd);
}

void		handle_peer_lost(char *cmd, t_server *server)
{
  char		*chname;
  char		*peer;
  t_channel	*chan;

  chname = strtok(cmd, ":");
  peer = strtok(NULL, ":");
  cmd = strtok(NULL, "");
  if (!chname || !peer || !cmd)
    return ;
  if ((chan = find_channel_by_name(server, chname)) == NULL)
    return ;
  remove_member_from_channel(chan, peer);
  push_msg_to_channel(chan, chname, cmd);
}

void		handle_peer_join(char *cmd, t_server *server)
{
  char		*chname;
  char		*peer;
  t_channel	*chan;

  chname = strtok(cmd, ":");
  peer = strtok(NULL, ":");
  cmd = strtok(NULL, "");
  if (!chname || !peer || !cmd || strcmp(peer, server->nickname) == 0)
    return ;
  if ((chan = find_channel_by_name(server, chname)) == NULL)
    return ;
  add_member_to_channel(chan, peer);
  push_msg_to_channel(chan, chname, cmd);
}

void		handle_peer_nick(char *cmd, t_server *server)
{
  char		*chname;
  char		*old;
  char		*new;
  t_channel	*chan;

  chname = strtok(cmd, ":");
  old = strtok(NULL, ":");
  new = strtok(NULL, ":");
  cmd = strtok(NULL, "");
  if (!chname || !old || !new || !cmd)
    return ;
  if ((chan = find_channel_by_name(server, chname)) == NULL)
    return ;
  change_member_name(chan, old, new);
  push_msg_to_channel(chan, chname, cmd);
}

void		handle_peer_add(char *cmd, t_server *server)
{
  char		*chname;
  char		*peer;
  t_channel	*chan;

  chname = strtok(cmd, ":");
  peer = strtok(NULL, "");
  if (!chname || !peer)
    return ;
  if ((chan = find_channel_by_name(server, chname)) == NULL)
    return ;
  add_member_to_channel(chan, peer);
}
