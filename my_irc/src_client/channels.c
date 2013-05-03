/*
** channels.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 11:13:12 2013 maxime ginters
** Last update Sun Apr 28 18:39:59 2013 maxime ginters
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "server.h"
#include "master.h"

t_channel	*create_channel(const char *name, char current, t_server *srv)
{
  t_channel	*chan;

  if ((chan = malloc(sizeof(t_channel))) == NULL)
    return (NULL);
  memset(chan->name, 0, CHANNEL_NAME_BUFFER_SIZE);
  strcpy(chan->name, name);
  chan->server = srv;
  chan->message_list = NULL;
  chan->member_list = NULL;
  chan->private = (name[0] == '#' ? 0 : 1);
  if (srv)
    list_add_elem_at_back(&srv->channel_list, chan);
  if (current == 1)
    set_current_channel(chan);
  if (srv && chan->private == 0)
    send_to_server(srv, "JOIN:%s", name);
  refresh_chanslist();
  return (chan);
}

t_channel	*find_current_channel(t_server *server)
{
  t_channel	*chan;
  int		size;

  size = (int)list_get_size(server->channel_list) - 1;
  while (size >= 0)
  {
    if ((chan = (t_channel*)GET_AT(server->channel_list, size)) != NULL)
      if (chan->current == 1)
        return (chan);
    --size;
  }
  return (NULL);
}

t_channel	*find_channel_by_name(t_server *server, const char *name)
{
  t_channel	*chan;
  int		size;

  size = (int)list_get_size(server->channel_list) - 1;
  while (size >= 0)
  {
    if ((chan = (t_channel*)GET_AT(server->channel_list, size)) != NULL)
        if (strcmp(chan->name, name) == 0)
        return (chan);
    --size;
  }
  return (NULL);
}

void		clean_channel(t_channel *chan)
{
  int		size;
  t_message	*mess;
  char		*str;

  size = (int)list_get_size(chan->message_list) - 1;
  while (size >= 0)
  {
    if ((mess = (t_message*)GET_AT(chan->message_list, size)) != NULL)
    {
      list_del_elem_at_position(&chan->message_list, size);
      free(mess);
    }
    --size;
  }
  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((str = (char*)GET_AT(chan->member_list, size)) != NULL)
    {
      list_del_elem_at_position(&chan->member_list, size);
      free(str);
    }
    --size;
  }
}

