/*
** commands.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:50:15 2013 maxime ginters
** Last update Sun Apr 28 21:23:02 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "commands.h"
#include "master.h"
#include "file.h"

t_command	commands[] = {
  {"/server", command_server, 7, "Usage: /server _address_ _port_"},
  {"/msg", command_message, 4, "Usage: /msg _channel_ _message_"},
  {"/nick", command_nick, 5, "Usage: /nick _nick_ (Min alphanum 2 characters"},
  {"/leave", command_leave, 6, "Usage: /leave _channel_"},
  {"/part", command_leave, 5, "Usage: /part _channel_"},
  {"/join", command_join, 5, "Usage: /join _channel_"},
  {"/list", command_list, 5, "Usage: /list _filter_"},
  {"/users", command_users, 6, "Usage: /users"},
  {"/window left", command_left, 12, "Usage: /window left"},
  {"/window right", command_right, 13, "Usage: /window right"},
  {"/quit", command_quit, 5, "Usage: /quit"},
  {"/send_file", command_send_file, 10, "Usage: /send_file _nickname_ _file_"},
  {"/accept_file", command_accept_file, 12, "Usage: /accept_file _nickname_"},
  {NULL, NULL, 0, NULL}
};

void		parse_command(char *cmd)
{
  int		i;
  int		size;
  t_channel	*chan;

  if ((chan = get_current_channel()) == NULL)
    chan = accueil;
  i = 0;
  while (commands[i].cmd != NULL)
  {
    size = strlen(commands[i].cmd);
    if (strncmp(cmd, commands[i].cmd, size) == 0)
    {
      if ((int)strlen(cmd) < commands[i].min_size)
        push_msg_to_channel(chan, "@client", commands[i].usage);
      else if ((commands[i].func)(cmd + commands[i].min_size + 1) != 0)
        push_msg_to_channel(chan, "@client", commands[i].usage);
      return ;
    }
    ++i;
  }
  if (strlen(cmd) > 0)
    command_message_default(cmd);
}

int		command_server(char *cmd)
{
  char		*host;
  char		*port;
  t_server	*server;
  char		buff[512];

  host = strtok(cmd, " ");
  port = strtok(NULL, " ");
  if (!host || !port)
    return (-1);
  sprintf(buff, "Try to connect to %s:%s", host, port);
  push_msg_to_channel(accueil, "@client", buff);
  if ((server = connect_to(host, port)) == NULL)
  {
    sprintf(buff, "Error: %s", strerror(errno));
    push_msg_to_channel(accueil, "@client", buff);
    return (0);
  }
  list_add_elem_at_back(&server_list, server);
  sprintf(buff, "Connected to %s:%s", host, port);
  push_msg_to_channel(accueil, "@client", buff);
  return (0);
}

void	command_message_default(char *cmd)
{
  t_channel	*chan;

  if ((chan = get_current_channel()) == NULL)
  {
    push_msg_to_channel(accueil, "@client", "You are not in a channel");
    return ;
  }
  if (strlen(cmd) == 0)
    return ;
  if (chan->private == 0)
    send_to_server(chan->server, "MSG:%s:%s", chan->name, cmd);
  else
    send_to_server(chan->server, "PRVMSG:%s:%s", chan->name, cmd);
}

int		command_send_file(char *cmd)
{
  char		*dest;
  t_channel	*chan;
  t_server	*server;

  dest = strtok(cmd, " ");
  cmd = strtok(NULL, "");
  if (!dest || !cmd)
    return (-1);
  if ((server = get_current_server()) == NULL)
  {
    push_msg_to_channel(accueil, "@client",
        "No current server, please /server before");
    return (0);
  }
  if ((chan = find_channel_by_name(server, dest)) == NULL)
    if ((chan = create_channel(dest, 1, server)) == NULL)
    {
      push_msg_to_channel(accueil, "@client", "Fail to create channel");
      return (0);
    }
  set_current_channel(chan);
  if (create_send_file(cmd, dest) != 0)
  {
    push_msg_to_channel(chan, "@client", "Fail to create send file");
    return (0);
  }
  send_to_server(chan->server, "SENDFILE:%s:%s", dest, cmd);
  return (0);
}

int		command_accept_file(char *cmd)
{
  t_channel	*chan;
  t_server	*server;

  if ((server = get_current_server()) == NULL)
    return (0);
  if ((chan = find_channel_by_name(server, cmd)) == NULL)
      return (0);
  set_current_channel(chan);
  if (create_get_file(cmd) != 0)
  {
    push_msg_to_channel(chan, "@client", "Fail to create get file");
    return (0);
  }
  send_to_server(chan->server, "ACCEPTFILE:%s", cmd);
  return (0);
}
