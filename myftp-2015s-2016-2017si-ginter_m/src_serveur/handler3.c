/*
** handler3.c for src_serveur in /Storage/Epitech/my_ftp/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:52:08 2013 maxime ginters
** Last update Sun Apr 14 19:52:39 2013 maxime ginters
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

void		send_filesize(t_client *client)
{
  struct stat	st;

  stat(client->filename, &st);
  dprintf(client->sockfd, "FILESIZE:%f%s",
      (double)st.st_size / 1024, TCP_SEPARATOR);
  client->send_statut = 1;
}

void	send_fileend(t_client *client)
{
  close(client->file_fd);
  client->send_statut = -1;
  dprintf(client->sockfd, "FILEEND%s", TCP_SEPARATOR);
  send_prompt(client);
}

void	handle_next(t_client *client, char cmd[], int size)
{
  int	rdsize;
  char	buff[4096];

  (void)cmd;
  (void)size;
  if (client->send_statut == 0)
    send_filesize(client);
  else if (client->send_statut == 1)
  {
    memset(buff, 0, 4096);
    strcpy(buff, "DATA:");
    rdsize = read(client->file_fd, &buff[5], 2048);
    if (rdsize <= 0)
      send_fileend(client);
    else
    {
      memcpy(&buff[5 + rdsize], TCP_SEPARATOR, SEPARATOR_LEN);
      write(client->sockfd, buff, 5 + rdsize + SEPARATOR_LEN);
    }
  }
}

