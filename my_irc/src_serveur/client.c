/*
** client.c for src_serveur in /Storage/Epitech/my_irc/src_serveur
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 22 11:39:09 2013 maxime ginters
** Last update Sun Apr 28 18:33:45 2013 maxime ginters
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "client.h"

t_list	client_list = NULL;

void	delete_client(t_client*client)
{
  int		size;

  size = (int)list_get_size(client_list) - 1;
  while (size >= 0)
  {
    if (client == (t_client*)GET_AT(client_list, size))
    {
      list_del_elem_at_position(&client_list, size);
      return;
    }
    --size;
  }
}

