/*
** file.c for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 19:17:37 2013 maxime ginters
** Last update Sun Apr 28 21:27:07 2013 maxime ginters
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "file.h"

t_file	*send_file = NULL;

#define FAIL_MALLOC { close(fd); return (-1); }
int	create_send_file(const char* file, const char *dest)
{
  int	fd;

  if (send_file)
    return (-1);
  if ((fd = open(file, O_RDONLY)) <= 2)
    return (-1);
  if ((send_file = malloc(sizeof(t_file))) == NULL)
    FAIL_MALLOC;
  send_file->fd = fd;
  strncpy(send_file->filename, file, FILENAME_BUFFER_SIZE);
  strncpy(send_file->peer, dest, NICK_BUFFER_SIZE);
  send_file->status = 0;
  return (0);
}

int	create_get_file(const char *peer)
{
  if (send_file)
    return (-1);
  if ((send_file = malloc(sizeof(t_file))) == NULL)
    return (-1);
  send_file->fd = 0;
  strncpy(send_file->peer, peer, NICK_BUFFER_SIZE);
  send_file->status = 0;
  return (0);
}

