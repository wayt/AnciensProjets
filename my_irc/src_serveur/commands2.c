/*
** commands2.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:34:21 2013 maxime ginters
** Last update Sun Apr 28 18:34:53 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include "channels.h"
#include "commands.h"

void	handle_nick_command(char *msg, t_client *client, t_server *server)
{
  int		size;
  t_channel	*chan;

  (void)server;
  size = is_nick_available(msg);
  if (size == -2)
    send_to_client(client, "SRVMSG:invalide nick");
  else
    if (size == -1)
      send_to_client(client, "SRVMSG:nick is not available");
    else
    {
      size = (int)list_get_size(channel_list) - 1;
      while (size >= 0)
      {
        if ((chan = (t_channel*)GET_AT(channel_list, size)) != NULL)
          if (is_client_in_channel(client, chan) == 0)
            broadcast_to_channel(chan, "PEERNICK:%s:%s:%s:%s now know as %s",
                chan->name, client->name, msg, client->name, msg);
        --size;
      }
      strncpy(client->name, msg, CLIENT_NAME_BUFFER_SIZE);
      send_to_client(client, "NICK:%s", client->name);
    }
}

void		handle_list_command(char *msg, t_client *client,
    t_server *server)
{
  int		size;
  t_channel	*chan;
  int		count;

  (void)server;
  size = (int)list_get_size(channel_list) - 1;
  count = 0;
  while (size >= 0)
  {
    if ((chan = (t_channel*)GET_AT(channel_list, size)) != NULL)
    {
      if (*msg != 0)
      {
        if (strstr(chan->name, msg) || ++count < -1)
          send_to_client(client, "SRVMSG:%s - %s", chan->name, chan->subject);
      }
      else if (++count > -1)
        send_to_client(client, "SRVMSG:%s - %s", chan->name, chan->subject);
    }
    --size;
  }
  if (count == 0)
    send_to_client(client, "SRVMSG:No channel");
}

void	handle_private_message_command(char *msg, t_client *client,
    t_server *server)
{
  char	*dest;

  (void)server;
  dest = strtok(msg, ":");
  msg = strtok(NULL, "");
  if (!dest || !msg)
    return ;
  broadcast_private_msg(client, dest, msg);
}
