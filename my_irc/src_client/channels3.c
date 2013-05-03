/*
** channels3.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:39:31 2013 maxime ginters
** Last update Sun Apr 28 18:39:51 2013 maxime ginters
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "server.h"
#include "master.h"

void		remove_channel(t_server *server, t_channel *chan)
{
  int		size;
  t_channel	*tmp;

  size = (int)list_get_size(server->channel_list) - 1;
  while (size >= 0)
  {
    if ((tmp = (t_channel*)GET_AT(server->channel_list, size)) != NULL)
      if (tmp == chan)
      {
        list_del_elem_at_position(&server->channel_list, size);
        if (tmp->current == 1)
          set_current_channel_by_index(0, 0);
        clean_channel(tmp);
        free(tmp);
      }
    --size;
  }
  refresh_chanslist();
}

void		remove_all_channel(t_server *server)
{
  int		size;
  t_channel	*tmp;

  size = (int)list_get_size(server->channel_list) - 1;
  while (size >= 0)
  {
    if ((tmp = (t_channel*)GET_AT(server->channel_list, size)) != NULL)
      remove_channel(server, tmp);
    --size;
  }
}

void		set_current_channel(t_channel *chan)
{
  int		csize;
  t_channel	*ctmp;
  int		ssize;
  t_server	*stmp;

  ssize = (int)list_get_size(server_list);
  if (accueil)
    accueil->current = 0;
  while (--ssize >= 0)
    if ((stmp = (t_server*)GET_AT(server_list, ssize)) != NULL)
    {
      csize = (int)list_get_size(stmp->channel_list);
      while (--csize >= 0)
        if ((ctmp = (t_channel*)GET_AT(stmp->channel_list, csize)) != NULL)
          ctmp->current = (ctmp == chan ? 1 : 0);
    }
  if (accueil && chan == accueil)
    accueil->current = 1;
  refresh_chanslist();
  refresh_mesgs(&interface, chan->message_list);
  refresh_users(&interface, chan->member_list);
}

void	push_msg_to_channel(t_channel *chan,
    const char *sender, const char *msg)
{
  t_message	*mess;

  if ((mess = malloc(sizeof(t_message))) == NULL)
      return ;
  strncpy(mess->sender, sender, CHANNEL_NAME_BUFFER_SIZE);
  strncpy(mess->msg, msg, BUFFER_SIZE);
  list_add_elem_at_front(&chan->message_list, mess);
  if (chan->current == 1)
    refresh_mesgs(&interface, chan->message_list);
}

void	add_member_to_channel(t_channel *chan, const char *name)
{
  PUSH_BACK(&chan->member_list, strdup(name));
  if (chan->current == 1)
    refresh_users(&interface, chan->member_list);
}
