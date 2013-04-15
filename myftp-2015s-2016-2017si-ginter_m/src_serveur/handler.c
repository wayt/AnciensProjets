/*
** handler.c for src_serveur in /Storage/Epitech/my_ftp/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:47:52 2013 maxime ginters
** Last update Sun Apr 14 19:53:28 2013 maxime ginters
*/

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "commands.h"

void	send_not_found(t_client *client)
{
  dprintf(client->sockfd, "TEXT:Error: command no found%s", TCP_SEPARATOR);
  send_prompt(client);
}

void		command_ls(t_client *client, char cmd[], int size)
{
  DIR		*dir;
  struct dirent	*drt;

  (void)cmd;
  (void)size;
  if ((dir = opendir(client->pwd)) != NULL)
  {
    while ((drt = readdir(dir)) != NULL)
      dprintf(client->sockfd, "TEXT:\t%s\n%s", drt->d_name, TCP_SEPARATOR);
  }
  else
    dprintf(client->sockfd, "TEXT:Error: %s\n%s",
        strerror(errno), TCP_SEPARATOR);
  send_prompt(client);
}

void	handle_ping(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  dprintf(client->sockfd, "PONG%s", TCP_SEPARATOR);
}

void	handle_command(t_client* client, char cmd[], int size)
{
  int	i;
  int	cmd_size;

  i = 0;
  while (sub_commands[i].cmd)
  {
    cmd_size = strlen(sub_commands[i].cmd);
    if (strncmp(sub_commands[i].cmd, cmd, cmd_size) == 0)
    {
      (sub_commands[i].func)(client, &cmd[cmd_size], size - cmd_size);
      return ;
    }
    ++i;
  }
  send_not_found(client);
}

void	send_prompt(t_client *client)
{
  dprintf(client->sockfd, "PROMPT%s", TCP_SEPARATOR);
}
