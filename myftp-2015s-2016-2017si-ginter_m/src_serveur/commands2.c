/*
** commands2.c for src_serveur in /Storage/Epitech/my_ftp/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 14 19:49:32 2013 maxime ginters
** Last update Sun Apr 14 19:50:28 2013 maxime ginters
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

void	command_pwd(t_client *client, char cmd[], int size)
{
  (void)cmd;
  (void)size;
  dprintf(client->sockfd, "TEXT:%s%s", client->pwd, TCP_SEPARATOR);
  send_prompt(client);
}

void	cd_fail(t_client *client, char buff[])
{
  chdir(buff);
  dprintf(client->sockfd, "TEXT:Error: you can't do that...%s",
      TCP_SEPARATOR);
  memset(client->pwd, 0, 512);
  getcwd(client->pwd, 512);
}
void	command_cd(t_client *client, char cmd[], int size)
{
  char	buff[512];

  if (size <= 1)
  {
    dprintf(client->sockfd, "TEXT:Error: invalide path%s", TCP_SEPARATOR);
    send_prompt(client);
    return ;
  }
  memset(buff, 0, 512);
  strcpy(buff, client->pwd);
  if (chdir(&cmd[1]) == -1)
    dprintf(client->sockfd, "TEXT:Error: %s%s",
        strerror(errno), TCP_SEPARATOR);
  else
  {
    memset(client->pwd, 0, 512);
    getcwd(client->pwd, 512);
    if (strstr(client->pwd, client->srv_pwd) == NULL)
      cd_fail(client, buff);
    else
      dprintf(client->sockfd, "TEXT:%s%s", client->pwd, TCP_SEPARATOR);
  }
  send_prompt(client);
}
