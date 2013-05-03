/*
** handler.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Apr 26 14:26:14 2013 maxime ginters
** Last update Sun Apr 28 21:23:30 2013 maxime ginters
*/

#ifndef HANDLER_H_
# define HANDLER_H_

#include "server.h"

typedef struct
{
  const char	*cmd;
  void (*func)(char*, t_server*);
}		t_handler;

extern t_handler	handlers[];

int	get_next_command_size(t_server *server);
int	process_handler(t_server *server);
void	parse_handler(char *msg, t_server *server);
void	handle_msg(char *cmd, t_server *server);
void	handle_nick(char *cmd, t_server *server);
void	handle_server_msg(char *cmd, t_server *server);
void	handle_peer_lost(char *cmd, t_server *server);
void	handle_peer_join(char *cmd, t_server *server);
void	handle_peer_nick(char *cmd, t_server *server);
void	handle_peer_add(char *cmd, t_server *server);
void	handle_send_file(char *cmd, t_server *server);
void	handle_accept_file(char *cmd, t_server *server);
void	handle_filename(char *cmd, t_server *server);
void	handle_send_abort(char *cmd, t_server *server);
void	handle_file_next(char *cmd, t_server *server);
void	handle_send_data(char *cmd, t_server *server);
void	handle_send_end(char *cmd, t_server *server);

#endif /* !HANDLER_H_ */
