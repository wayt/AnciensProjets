/*
** commands2.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:41:11 2013 maxime ginters
** Last update Sun Apr 28 18:41:29 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "commands.h"
#include "master.h"

int		command_list(char *cmd)
{
  t_server	*server;

  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil, "@client",
        "No current server, please /server before");
    return (0);
  }
  send_to_server(server, "LIST:%s", (*cmd == 0 ? "" : cmd + 1));
  return (0);
}

int		command_users(char *cmd)
{
  t_channel	*chan;
  int		size;
  char		*user;

  (void)cmd;
  if ((chan = get_current_channel()) == NULL)
  {
    push_msg_to_channel(accueil, "@client", "Please join a channel before\n");
    return (0);
  }
  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((user = (char*)GET_AT(chan->member_list, size)) != NULL)
      push_msg_to_channel(chan, chan->name, user);
    --size;
  }
  return (0);
}

int	command_left(char *cmd)
{
  int	srv;
  int	chn;

  (void)cmd;
  srv = -1;
  chn = -1;
  if (get_currents_index(&srv, &chn) != 0)
    return (0);
  if (chn > 0)
    set_current_channel_by_index(srv, --chn);
  else if (srv > 0)
    set_current_channel_by_index(--srv, -1);
  else
    set_current_channel(accueil);
  return (0);
}

int	command_right(char *cmd)
{
  int	srv;
  int	chn;

  (void)cmd;
  srv = -1;
  chn = -1;
  if (get_currents_index(&srv, &chn) != 0)
  {
    set_current_channel_by_index(0, 0);
    return (0);
  }
  if (chn < get_channel_count(srv) - 1)
    set_current_channel_by_index(srv, chn + 1);
  else if (srv < (int)list_get_size(server_list) - 1)
    set_current_channel_by_index(++srv, 0);
  return (0);
}

int	command_quit(char *cmd)
{
  (void)cmd;
  running = false;
  return (0);
}
