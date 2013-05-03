/*
** commands.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 11:05:12 2013 maxime ginters
** Last update Sun Apr 28 21:30:54 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include "channels.h"
#include "commands.h"

t_command	commands[] = {
  {"MSG:", handle_msg_command},
  {"JOIN:", handle_join_command},
  {"LEAVE:", handle_leave_command},
  {"NICK:", handle_nick_command},
  {"LIST:", handle_list_command},
  {"PRVMSG:", handle_private_message_command},
  {"SENDFILE:", handle_send_file},
  {"ACCEPTFILE:", handle_accept_file},
  {"FILENAME:", handle_filename},
  {"SENDABORT:", handle_send_abort},
  {"FILENEXT:", handle_file_next},
  {"SENDDATA:", handle_send_data},
  {"SENDEND:", handle_send_end},
  {NULL, NULL}
};

void	parse_command(char *msg, t_client *client, t_server *server)
{
  int	i;
  int	size;

  i = 0;
  while (commands[i].cmd)
  {
    size = strlen(commands[i].cmd);
    if (strncmp(msg, commands[i].cmd, size) == 0)
    {
      (commands[i].func)(msg + size, client, server);
      return ;
    }
    ++i;
  }
}

void		handle_msg_command(char *msg, t_client *client, t_server *server)
{
  char		*chname;
  t_channel	*chan;

  (void)server;
  chname = strtok(msg, ":");
  msg = strtok(NULL , "");
  if (!chname || !msg || strlen(msg) == 0)
    return ;
  if ((chan = find_channel_by_name(chname)) == NULL)
    return ;
  broadcast_to_channel(chan, "MSG:%s:%s:%s", chan->name, client->name, msg);

}

void	handle_join_command(char *msg, t_client *client, t_server *server)
{
  t_channel	*chan;
  char		buff[CHANNEL_NAME_BUFFER_SIZE];

  (void)server;
  if (strlen(msg) == 0)
    return ;
  buff[0] = '#';
  strncpy((*msg == '#' ? buff : &buff[1]), msg, CHANNEL_NAME_BUFFER_SIZE - 1);
  if ((chan = find_channel_by_name(buff)) == NULL)
  {
    if ((chan = create_channel(buff, client)) == NULL)
    {
      fprintf(stderr, "Error: %s\n", strerror(errno));
      return ;
    }
  }
  else
    add_client_to_channel(client, chan);
  send_all_peer_to_client(chan, client);
  broadcast_to_channel(chan, "PEERJOIN:%s:%s:%s join channel",
      chan->name, client->name, client->name);
}

void	handle_leave_command(char *msg, t_client *client, t_server *server)
{
  t_channel	*chan;

  (void)server;
  if (strlen(msg) == 0)
    return ;
  if ((chan = find_channel_by_name(msg)) == NULL)
    return ;
  remove_client_from_channel(client, chan);
  broadcast_to_channel(chan, "PEERLEAVE:%s:%s:%s left channel",
      chan->name, client->name, client->name);
}

