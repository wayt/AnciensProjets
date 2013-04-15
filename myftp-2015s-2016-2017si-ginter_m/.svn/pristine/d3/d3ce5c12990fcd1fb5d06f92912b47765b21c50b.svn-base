/*
** commands.h for serveur in /Storage/Epitech/my_ftp/serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 14:17:43 2013 maxime ginters
** Last update Sun Apr 14 19:53:35 2013 maxime ginters
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

#include "serveur.h"

#define TCP_SEPARATOR "\\/!@#$%^&*\\"
#define SEPARATOR_LEN strlen(TCP_SEPARATOR)

typedef struct
{
  const char	*cmd;
  void		(*func)(t_client*, char[], int);
}		t_cmd;

extern t_cmd	commands[];
extern t_cmd	sub_commands[];

void	parse_buffer(t_client *client);
void	parse_command(t_client *client, char cmd[], int size);

void	handle_command(t_client* client, char cmd[], int size);
void	command_ls(t_client* client, char cmd[], int size);
void	handle_ping(t_client *client, char cmd[], int size);
void	command_get(t_client *client, char cmd[], int size);
void	command_pwd(t_client *client, char cmd[], int size);
void	command_cd(t_client *client, char cmd[], int size);
void	handle_filename(t_client *client, char cmd[], int size);
void	handle_filesize(t_client *client, char cmd[], int size);
void	handle_data(t_client *client, char cmd[], int size);
void	handle_fileend(t_client *client, char cmd[], int size);
void	handle_next(t_client *client, char cmd[], int size);
void	handle_senderror(t_client *client, char cmd[], int size);

void	send_not_found(t_client *client);
void	send_prompt(t_client *client);

#endif /* !COMMANDS_H_ */
