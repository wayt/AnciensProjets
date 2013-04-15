/*
** commands.h for client in /Storage/Epitech/my_ftp/client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 17:16:25 2013 maxime ginters
** Last update Sun Apr 14 19:38:20 2013 maxime ginters
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

#include "client.h"

#define TCP_SEPARATOR "\\/!@#$%^&*\\"
#define SEPARATOR_LEN strlen(TCP_SEPARATOR)

typedef struct
{
  const char	*cmd;
  void		(*func)(t_client*, char[], int);
}		t_cmd;

extern t_cmd	commands[];
extern t_cmd	local_cmds[];

void	handle_command(t_client *client, char cmd[], int size);
void	command_quit(t_client *client, char cmd[], int size);
void	command_put(t_client *client, char cmd[], int size);

void	handle_receiv(t_client *client);
void	parse_command(t_client *client, char cmd[], int size);
void	handle_text(t_client *client, char data[], int size);
void	handle_prompt(t_client *client, char cmd[], int size);
void	handle_pong(t_client *client, char cmd[], int size);
void	handle_filename(t_client *client, char cmd[], int size);
void	handle_filesize(t_client *client, char cmd[], int size);
void	handle_data(t_client *client, char cmd[], int size);
void	handle_fileend(t_client *client, char cmd[], int size);
void	handle_next(t_client *client, char cmd[], int size);
void	handle_senderror(t_client *client, char cmd[], int size);

#endif /* !COMMANDS_H_ */
