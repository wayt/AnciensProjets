/*
** channels2.c for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:32:00 2013 maxime ginters
** Last update Sun Apr 28 18:32:28 2013 maxime ginters
*/

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "channels.h"

void		remove_client_from_channel(t_client *client, t_channel *chan)
{
  t_client	*tmp;
  int		size;

  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((tmp = (t_client*)GET_AT(chan->member_list, size)) != NULL)
      if (tmp == client)
      {
        list_del_elem_at_position(&chan->member_list, size);
        printf("Client removed from chan %s\n", chan->name);
        return ;
      }
    --size;
  }
}

void		broadcast_to_channel(t_channel *chan, const char *msg, ...)
{
  int		size;
  t_client	*peer;
  va_list	ap;
  char		buff[2048];

  va_start(ap, msg);
  vsprintf(buff, msg, ap);
  va_end(ap);
  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((peer = (t_client*)GET_AT(chan->member_list, size)) != NULL)
      send_to_client(peer, "%s", buff);
    --size;
  }
}

int		is_client_in_channel(t_client *client, t_channel *chan)
{
  int		size;
  t_client	*tmp;

  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((tmp = (t_client*)GET_AT(chan->member_list, size)) != NULL)
      if (tmp == client)
        return (0);
    --size;
  }
  return (-1);
}

void		send_all_peer_to_client(t_channel *chan, t_client *client)
{
  int		size;
  t_client	*peer;

  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((peer = (t_client*)GET_AT(chan->member_list, size)) != NULL)
      send_to_client(client, "PEERADD:%s:%s", chan->name, peer->name);
    --size;
  }
}

void		broadcast_private_msg(t_client *sender, char *dest, char *msg)
{
  t_client	*peer;

  send_to_client(sender, "MSG:%s:%s:%s", dest, sender->name, msg);
  if ((peer = get_client_by_name(dest)) != NULL)
    send_to_client(peer, "MSG:%s:%s:%s", sender->name, sender->name, msg);
}
