/*
** channels.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 12:42:39 2013 maxime ginters
** Last update Sun Apr 28 18:32:34 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "channels.h"

t_list	channel_list = NULL;

t_channel	*create_channel(const char *name, t_client *client)
{
  t_channel	*chan;

  if ((chan = find_channel_by_name(name)) != NULL)
  {
    add_client_to_channel(client, chan);
    return (NULL);
  }
  if ((chan = malloc(sizeof(t_channel))) == NULL)
      return (NULL);
  strncpy(chan->name, name, CHANNEL_NAME_BUFFER_SIZE);
  memset(chan->subject, 0, CHANNEL_SUBJECT_BUFFER_SIZE);
  add_client_to_channel(client, chan);
  PUSH_BACK(&channel_list, chan);
  return (chan);
}

t_channel	*find_channel_by_name(const char *name)
{
  t_channel	*chan;
  int		size;

  size = (int)list_get_size(channel_list) - 1;
  while (size >= 0)
  {
    if ((chan = (t_channel*)GET_AT(channel_list, size)) != NULL)
        if (strcmp(chan->name, name) == 0)
        return (chan);
    --size;
  }
  return (NULL);
}

void	add_client_to_channel(t_client *client, t_channel *chan)
{
  t_client	*tmp;
  int		size;

  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((tmp = (t_client*)GET_AT(chan->member_list, size)) != NULL)
      if (tmp == client)
        return;
    --size;
  }
  printf("Client added to chan %s\n", chan->name);
  PUSH_BACK(&chan->member_list, client);
}

