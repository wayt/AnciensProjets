/*
** channels2.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:38:57 2013 maxime ginters
** Last update Sun Apr 28 18:39:19 2013 maxime ginters
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "server.h"
#include "master.h"

void	remove_member_from_channel(t_channel *chan, const char *name)
{
  int	size;
  char	*str;

  size = (int)list_get_size(chan->member_list) - 1;
  while (size >= 0)
  {
    if ((str = (char*)GET_AT(chan->member_list, size)) != NULL)
      if (strcmp(str, name) == 0)
      {
        list_del_elem_at_position(&chan->member_list, size);
        free(str);
        return ;
      }
    --size;
  }
  if (chan->current == 1)
    refresh_users(&interface, chan->member_list);
}

void	change_member_name(t_channel *chan, const char *old, const char *new)
{
  remove_member_from_channel(chan, old);
  add_member_to_channel(chan, new);
}

void		set_current_channel_by_index(int srv, int chn)
{
  int		ssize;
  t_server	*server;
  int		csize;
  t_channel	*chan;

  ssize = (int)list_get_size(server_list);
  while (--ssize >= 0)
    if ((server = (t_server*)GET_AT(server_list, ssize)) != NULL)
      if (srv == ssize)
      {
        csize = (int)list_get_size(server->channel_list);
        while (--csize >= 0)
          if ((chan = (t_channel*)GET_AT(server->channel_list, csize)) != NULL)
            if ((chn == -1 && csize == (int)list_get_size(
                    server->channel_list)) || (chn == csize))
            {
              set_current_channel(chan);
              return ;
            }
      }
}

int		get_channel_count(int srv)
{
  t_server	*server;

  if ((server = (t_server*)GET_AT(server_list, srv)) == NULL)
    return (0);
  return ((int)list_get_size(server->channel_list));
}

void		refresh_chanslist()
{
  int		ssize;
  t_server	*server;
  int		csize;
  t_channel	*chan;
  t_list	list;
  t_channel	*curr;

  list = NULL;
  curr = NULL;
  ssize = (int)list_get_size(server_list);
  while (--ssize >= 0)
    if ((server = (t_server*)GET_AT(server_list, ssize)) != NULL)
      {
        csize = (int)list_get_size(server->channel_list);
        while (--csize >= 0)
          if ((chan = (t_channel*)GET_AT(server->channel_list, csize)) != NULL)
          {
            list_add_elem_at_front(&list, chan);
            curr = (chan->current == 1 ? chan : curr);
          }
      }
  if (accueil)
    list_add_elem_at_front(&list, accueil);
  refresh_chans(&interface, list, curr ? curr : accueil);
  list_clear(&list);
}
