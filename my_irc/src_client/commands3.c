/*
** commands3.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:41:46 2013 maxime ginters
** Last update Sun Apr 28 18:42:08 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "commands.h"
#include "master.h"

int	command_message(char *cmd)
{
  t_server	*server;
  t_channel	*chan;
  char		*chname;
  char		*msg;

  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil, "@client",
        "No current server, please /server before");
    return (0);
  }
  chname = strtok(cmd, " ");
  msg = strtok(NULL, "");
  if (!chname || !msg || strlen(msg) == 0)
    return (-1);
  if ((chan = find_channel_by_name(server, chname)) == NULL)
    if ((chan = create_channel(chname, 1, server)) == NULL)
    {
      push_msg_to_channel(accueil, "@client", "Fail to create channel");
      return (0);
    }
  set_current_channel(chan);
  send_to_server(server, "MSG:%s:%s", chan->private == 1 ? "PRVMSG" : "MSG",
      chname, msg);
  return (0);
}

int		command_nick(char *cmd)
{
  t_server	*server;

  if (!cmd || strlen(cmd) <= 1)
    return (-1);
  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil,
        "@client", "No current server, please /server before");
    return (0);
  }
  send_to_server(server, "NICK:%s", cmd);
  return (0);
}

int		command_leave(char *cmd)
{
  t_server	*server;
  t_channel	*chan;

  if (!cmd)
    return (-1);
  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil, "@client",
        "No current server, please /server before");
    return (0);
  }
  if ((chan = find_channel_by_name(server, cmd)) == NULL)
  {
    push_msg_to_channel(accueil, "@client", "You are not in this channel");
    return (0);
  }
  remove_channel(server, chan);
  send_to_server(server, "LEAVE:%s", cmd);
  return (0);
}

int		command_join(char *cmd)
{
  t_server	*server;
  t_channel	*chan;
  char		buff[CHANNEL_NAME_BUFFER_SIZE];

  if (!cmd)
    return (-1);
  buff[0] = '#';
  strncpy(*cmd == '#' ? buff : &buff[1], cmd, CHANNEL_NAME_BUFFER_SIZE - 1);
  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil, "@client",
        "No current server, please /server before");
    return (0);
  }
  if ((chan = find_channel_by_name(server, buff)) == NULL)
    if ((chan = create_channel(buff, 1, server)) == NULL)
    {
      push_msg_to_channel(accueil, "@client", "Fail to create channel");
      return (0);
    }
  set_current_channel(chan);
  return (0);
}

