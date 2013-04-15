/*
** handler2.c for src_serveur in /Storage/Epitech/my_ftp/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:50:32 2013 maxime ginters
** Last update Sun Apr 14 19:56:48 2013 maxime ginters
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

void	handle_filename(t_client *client, char cmd[], int size)
{
  int	fd;

  (void)client;
  (void)size;
  if ((fd = open(cmd, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
  {
    dprintf(client->sockfd, "SENDERROR:Error: %s%s",
        strerror(errno), TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  printf("New file : %s\n", cmd);
  client->file_fd = fd;
  client->filesize = 0;
  client->received = 0;
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_filesize(t_client *client, char cmd[], int size)
{
  (void)size;
  client->filesize = atof(cmd);
  printf("Filesize : %f\n", client->filesize);
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_data(t_client *client, char cmd[], int size)
{
  if (client->file_fd == -1)
  {
    dprintf(client->sockfd,
        "SENDERROR:Error: receiv data but have no file desc%s", TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  write(client->file_fd, cmd, size);
  client->received += ((double)size / 1024);
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_fileend(t_client *client, char cmd[], int size)
{
  if (client->file_fd <= 2)
  {
    dprintf(client->sockfd,
        "SENDERROR:Error: receiv file end but have no file desc%s",
        TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  (void)cmd;
  (void)size;
  close(client->file_fd);
  client->filesize = 0;
  client->received = 0;
  send_prompt(client);
}

void	handle_senderror(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  if (client->file_fd > 2)
    close(client->file_fd);
  client->file_fd = -1;
  memset(client->filename, 0, 512);
  client->send_statut = -1;
  send_prompt(client);
}
