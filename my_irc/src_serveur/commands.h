/*
** commands.h for src_serveur in /home/fest/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 11:01:27 2013 maxime ginters
** Last update Sun Apr 28 21:50:06 2013 maxime ginters
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

#include "client.h"
#include "server.h"

typedef struct
{
  const char	*cmd;
  void	(*func)(char*, t_client*, t_server*);
}	t_command;

extern t_command	commands[];

void	parse_command(char *cmd, t_client *client, t_server *server);
void	handle_msg_command(char *msg, t_client *client, t_server *server);
void	handle_join_command(char *msg, t_client *client, t_server *server);
void	handle_leave_command(char *msg, t_client *client, t_server *server);
void	handle_nick_command(char *msg, t_client *client, t_server *server);
void	handle_list_command(char *msg, t_client *client, t_server *server);
void	handle_private_message_command(char *msg, t_client *client, t_server *server);
void	handle_private_nick_command(char *msg, t_client *client, t_server *server);
void	handle_send_file(char *msg, t_client *client, t_server *server);
void	handle_accept_file(char *msg, t_client *client, t_server *server);
void	handle_filename(char *msg, t_client *client, t_server *server);
void	handle_send_abort(char *msg, t_client *client, t_server *server);
void	handle_file_next(char *msg, t_client *client, t_server *server);
void	handle_send_data(char *msg, t_client *client, t_server *server);
void	handle_send_end(char *msg, t_client *client, t_server *server);

#endif /* !COMMANDS_H_ */
