/*
** commands.c for serveur in /Storage/Epitech/my_ftp/serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 14:20:28 2013 maxime ginters
** Last update Sun Apr 14 19:53:18 2013 maxime ginters
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

t_cmd	commands[] = {
  {"COMMAND:", &handle_command},
  {"PING", &handle_ping},
  {"FILENAME:", &handle_filename},
  {"FILESIZE:", &handle_filesize},
  {"DATA:", &handle_data},
  {"FILEEND", &handle_fileend},
  {"NEXT", &handle_next},
  {"SENDERROR", &handle_senderror},
  {NULL, NULL}
};

t_cmd	sub_commands[] = {
  {"ls", &command_ls},
  {"get", &command_get},
  {"pwd", &command_pwd},
  {"cd", &command_cd},
  {NULL, NULL}
};

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

void	parse_buffer(t_client *client)
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
  while (i >= 0 && commands[i].cmd)
  {
    cmd_size = strlen(commands[i].cmd);
    if (strncmp(commands[i].cmd, cmd, cmd_size) == 0)
    {
      (commands[i].func)(client, &cmd[cmd_size], size - cmd_size);
      return ;
    }
    ++i;
  }
  printf("Commande no found :\n");
  write(1, cmd, size);
  printf("\n\n");
  if (i >= 0)
    send_not_found(client);
}

void	command_get(t_client *client, char cmd[], int size)
{
  int	fd;

  if (size <= 1)
  {
    dprintf(client->sockfd, "TEXT:Error: invalide filename%s", TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  if ((fd = open(&cmd[1], O_RDONLY)) == -1)
  {
    dprintf(client->sockfd, "TEXT:Error: %s%s",
        strerror(errno), TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  client->send_statut = 0;
  memset(client->filename, 0, 512);
  strcpy(client->filename, &cmd[1]);
  client->file_fd = fd;
  dprintf(client->sockfd, "FILENAME:%s%s", &cmd[1], TCP_SEPARATOR);
}
