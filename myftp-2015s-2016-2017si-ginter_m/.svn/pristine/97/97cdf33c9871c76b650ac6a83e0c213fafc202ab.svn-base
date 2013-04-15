/*
** commands.c for client in /Storage/Epitech/my_ftp/client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 11 17:17:04 2013 maxime ginters
** Last update Sun Apr 14 19:38:37 2013 maxime ginters
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

t_cmd	commands[] = {
  {"TEXT:", &handle_text},
  {"PROMPT", &handle_prompt},
  {"PONG", &handle_pong},
  {"FILENAME:", &handle_filename},
  {"FILESIZE:", &handle_filesize},
  {"DATA:", &handle_data},
  {"FILEEND", &handle_fileend},
  {"NEXT", &handle_next},
  {"SENDERROR:", &handle_senderror},
  {NULL, NULL}
};

t_cmd	local_cmds[] = {
  {"quit", &command_quit},
  {"put", &command_put},
  {NULL, NULL}
};

unsigned int	get_file_size(const char* filename)
{
  struct stat	st;

  stat(filename, &st);
  return (st.st_size);
}

void	send_fileend(t_client *client)
{
  close(client->file_fd);
  client->send_statut = -1;
  dprintf(client->sockfd, "FILEEND%s", TCP_SEPARATOR);
  printf("\nSUCCESS\n");
}

void	send_filesize(t_client *client)
{
  client->filesize = (double)get_file_size(client->filename) / 1024;
  dprintf(client->sockfd, "FILESIZE:%f%s", client->filesize, TCP_SEPARATOR);
  printf("File size : %.2f KBytes\n", client->filesize);
  client->received = 0;
  client->send_statut = 1;
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
      client->received += (double)rdsize / 1024;
      printf("\r                                               ");
      printf("\rRecv : %.2f/%.2f (%d%%)", client->received, client->filesize,
          (int)((client->received / client->filesize) * 100.0f));
    }
  }
  client->wait_data = 1;
}

void	handle_senderror(t_client *client, char cmd[], int size)
{
  (void)size;
  if (client->file_fd > 2)
    close(client->file_fd);
  client->file_fd = -1;
  memset(client->filename, 0, 512);
  client->send_statut = -1;
  fprintf(stderr, "%s", cmd);
}
