/*
** handler2.c for src_client in /Storage/Epitech/my_ftp/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:35:03 2013 maxime ginters
** Last update Sun Apr 14 19:38:51 2013 maxime ginters
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

void	handle_pong(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  client->wait_pong = 0;
}

void	handle_filename(t_client *client, char cmd[], int size)
{
  int	fd;

  (void)client;
  (void)size;
  if ((fd = open(cmd, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
  {
    fprintf(stderr, "Error: fail to create local file %s\n", cmd);
    dprintf(client->sockfd, "SENDERROR%s", TCP_SEPARATOR);
    return ;
  }
  client->file_fd = fd;
  client->filesize = 0;
  client->received = 0;
  printf("create file : %s\n", cmd);
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_filesize(t_client *client, char cmd[], int size)
{
  (void)size;
  client->filesize = atof(cmd);
  printf("File size : %.2f KBytes\n", client->filesize);
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_data(t_client *client, char cmd[], int size)
{
  if (client->file_fd == -1)
  {
    fprintf(stderr, "Error: receiv data but have no file desc\n");
    dprintf(client->sockfd, "SENDERROR%s", TCP_SEPARATOR);
    return;
  }
  write(client->file_fd, cmd, size);
  client->received += ((double)size / 1024);
  printf("\r                                                         ");
  printf("\rRecv : %.2f/%.2f (%d%%)", client->received, client->filesize,
      (int)((client->received / client->filesize) * 100.0f));
  dprintf(client->sockfd, "NEXT%s", TCP_SEPARATOR);
}

void	handle_fileend(t_client *client, char cmd[], int size)
{
  if (client->file_fd <= 2)
  {
    fprintf(stderr, "Error: receiv file end but have no file desc\n");
    return;
  }
  printf("\nSUCCESS\n");
  (void)cmd;
  (void)size;
  close(client->file_fd);
  client->filesize = 0;
  client->received = 0;
}
