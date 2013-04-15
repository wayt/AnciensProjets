/*
** handler.c for src_client in /Storage/Epitech/my_ftp/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:32:52 2013 maxime ginters
** Last update Sun Apr 14 19:34:58 2013 maxime ginters
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

int	get_serparator(char buff[], int size)
{
  int	i;

  i = 0;
  while (i < size)
  {
    if (strncmp(&buff[i], TCP_SEPARATOR, SEPARATOR_LEN) == 0)
      return (i);
    ++i;
  }
  return (-1);
}

void	handle_receiv(t_client *client)
{
  int	index;
  char	data[4096];

  while ((index = get_serparator(client->buffer, client->buff_size)) != -1)
  {
    memset(data, 0, 4096);
    memcpy(data, client->buffer, index);
    parse_command(client, data, index);
    memset(client->buffer, 0, index);
    client->buff_size -= (index + SEPARATOR_LEN);
    memcpy(client->buffer, &client->buffer[index + SEPARATOR_LEN],
        client->buff_size);
    memset(&client->buffer[client->buff_size], 0, 4096 - client->buff_size);
  }
}

void	parse_command(t_client *client, char cmd[], int size)
{
  int	i;
  int	cmd_size;

  i = 0;
  while (commands[i].cmd)
  {
    cmd_size = strlen(commands[i].cmd);
    if (strncmp(commands[i].cmd, cmd, cmd_size) == 0)
    {
      (commands[i].func)(client, &cmd[cmd_size], size - cmd_size);
      return ;
    }
    ++i;
  }
  fprintf(stderr, "Error: unknow command reveiced : [%s]\n", cmd);
}

void	handle_text(t_client *client, char data[], int size)
{
  (void)client;
  write(1, data, size);
}

void	handle_prompt(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  printf("\nFTP> ");
  fflush(stdout);
  client->wait_data = 0;
}
