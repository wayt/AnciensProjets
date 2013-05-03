/*
** commands.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:50:15 2013 maxime ginters
** Last update Sun Apr 28 19:49:02 2013 maxime ginters
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

typedef struct
{
  const char	*cmd;
  int (*func)(char* cmd);
  int		min_size;
  const char*	usage;
}		t_command;

extern t_command commands[];

void	parse_command(char *cmd);
int	command_server(char *cmd);
void	command_message_default(char *cmd);
int	command_message(char *cmd);
int	command_nick(char *cmd);
int	command_channel(char *cmd);
int	command_leave(char *cmd);
int	command_join(char *cmd);
int	command_list(char *cmd);
int	command_users(char *cmd);
int	command_left(char *cmd);
int	command_right(char *cmd);
int	command_quit(char *cmd);
int	command_accept_file(char *cmd);
int	command_send_file(char *cmd);

#endif /* !COMMANDS_H_ */
