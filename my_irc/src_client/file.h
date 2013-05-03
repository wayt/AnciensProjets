/*
** file.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 19:14:46 2013 maxime ginters
** Last update Sun Apr 28 21:24:32 2013 maxime ginters
*/

#ifndef FILE_H_
# define FILE_H_

#include <string.h>
#include "server.h"

#define FILENAME_BUFFER_SIZE 512

typedef struct
{
  int	fd;
  char	filename[FILENAME_BUFFER_SIZE];
  char	peer[NICK_BUFFER_SIZE];
  char	status;
}	t_file;

extern t_file	*send_file;

int	create_send_file(const char* file, const char *dest);
int	create_get_file(const char *peer);

#endif /* !FILE_H_ */
