/*
** command2.c for src_client in /Storage/Epitech/my_ftp/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:35:40 2013 maxime ginters
** Last update Sun Apr 14 19:36:58 2013 maxime ginters
*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "client.h"
#include "commands.h"

void	handle_command(t_client *client, char cmd[], int size)
{
  int	i;
  int	cmd_size;

  if (strlen(cmd) < 1)
  {
    handle_prompt(client, NULL, 0);
    return ;
  }
  i = 0;
  while (local_cmds[i].cmd)
  {
    cmd_size = strlen(local_cmds[i].cmd);
    if (strncmp(local_cmds[i].cmd, cmd, cmd_size) == 0)
    {
      (local_cmds[i].func)(client, &cmd[cmd_size], size - cmd_size);
      return ;
    }
    ++i;
  }
  dprintf(client->sockfd, "COMMAND:%s%s", cmd, TCP_SEPARATOR);
  client->wait_data = 1;
}

void	command_put(t_client *client, char cmd[], int size)
{
  int	fd;

  if (size <= 1)
  {
    fprintf(stderr, "Error: invalide filename");
    return ;
  }
  if ((fd = open(&cmd[1], O_RDONLY)) == -1)
  {
    fprintf(stderr, "Error: %s", strerror(errno));
    return ;
  }
  client->send_statut = 0;
  memset(client->filename, 0, 512);
  strcpy(client->filename, &cmd[1]);
  client->file_fd = fd;
  dprintf(client->sockfd, "FILENAME:%s%s", &cmd[1], TCP_SEPARATOR);
}

void	command_quit(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  close(client->sockfd);
  printf("Bye bye !\n");
  exit(0);
}
