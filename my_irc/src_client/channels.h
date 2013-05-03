/*
** channels.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 11:13:12 2013 maxime ginters
** Last update Sun Apr 28 18:41:00 2013 maxime ginters
*/

#ifndef CHANNELS_H_
# define CHANNELS_H_

#include "server.h"

#define CHANNEL_NAME_BUFFER_SIZE 128

typedef struct
{
  char	sender[CHANNEL_NAME_BUFFER_SIZE];
  char	msg[BUFFER_SIZE];
}	t_message;
typedef struct
{
  char		name[CHANNEL_NAME_BUFFER_SIZE];
  t_list	member_list;
  char		current;
  t_server	*server;
  t_list	message_list;
  char		private;
}	t_channel;

t_channel	*create_channel(const char *name, char current, t_server *srv);
t_channel	*find_current_channel(t_server *server);
t_channel	*find_channel_by_name(t_server *server, const char *name);
void		remove_channel(t_server *server, t_channel *chan);
void		remove_all_channel(t_server *server);
void		set_current_channel(t_channel *chan);
void		push_msg_to_channel(t_channel *chan, const char *sender, const char *msg);
void		add_member_to_channel(t_channel *chan, const char *name);
void		remove_member_from_channel(t_channel *chan, const char *name);
void		change_member_name(t_channel *chan, const char *old, const char *new);
int		get_channel_count(int srv);
void		set_current_channel_by_index(int srv, int chn);
void		refresh_chanslist();
void		clean_channel(t_channel *chan);

#endif /* !CHANNELS_H_ */
