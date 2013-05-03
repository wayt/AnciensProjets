/*
** channels.h for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 12:42:33 2013 maxime ginters
** Last update Sun Apr 28 18:51:00 2013 maxime ginters
*/

#ifndef CHANNELS_H_
# define CHANNELS_H_

#include "client.h"
#include "list.h"

#define CHANNEL_NAME_BUFFER_SIZE 128
#define CHANNEL_SUBJECT_BUFFER_SIZE 512

typedef struct
{
  char		name[CHANNEL_NAME_BUFFER_SIZE];
  t_list	member_list;
  char		subject[CHANNEL_SUBJECT_BUFFER_SIZE];
}	t_channel;

extern t_list	channel_list;

t_channel	*create_channel(const char *name, t_client *client);
t_channel	*find_channel_by_name(const char *name);
void		add_client_to_channel(t_client *client, t_channel *chan);
void		remove_client_from_channel(t_client *client, t_channel *chan);
void		broadcast_to_channel(t_channel *chan, const char *msg, ...);
int		is_client_in_channel(t_client *client, t_channel *chan);
void		send_all_peer_to_client(t_channel *chan, t_client *client);
void		broadcast_private_msg(t_client *sender, char *dest, char *msg);

#endif /* !CHANNELS_H_ */
