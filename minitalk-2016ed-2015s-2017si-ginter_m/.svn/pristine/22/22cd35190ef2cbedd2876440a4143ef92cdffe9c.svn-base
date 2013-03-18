/*
** client.c for Server in /home/fest/Epitech/Minitalk/Server
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 17 15:03:46 2012 maxime ginters
** Last update Sun Nov 18 12:36:51 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "client.h"

void		remove_client(int pid)
{
  t_client	*prev;
  t_client	*itr;

  prev = NULL;
  itr = client_list;
  while (itr != NULL)
  {
    if (itr->from_pid == pid)
    {
      free(itr->str);
      if (prev != NULL)
        prev->next = itr->next;
      else
        client_list = itr->next;
      return;
    }
    prev = itr;
    itr = itr->next;
  }
}

t_client	*add_client(int pid)
{
  t_client	*new;
  t_client	*itr;

  new = xmalloc(sizeof(t_client));
  new->from_pid = pid;
  new->str = my_strdup("");
  new->str_i = 0;
  new->byte_i = 0;
  new->next = NULL;
  itr = client_list;
  if (itr == NULL)
    client_list = new;
  else
  {
    while (itr->next != NULL)
      itr = itr->next;
    itr->next = new;
  }
  return (new);
}

t_client	*find_client(int pid)
{
  t_client	*itr;

  itr = client_list;
  while (itr != NULL)
  {
    if (itr->from_pid == pid)
      return (itr);
    itr = itr->next;
  }
  return (NULL);
}

int		count_client()
{
  int		i;
  t_client	*itr;

  i = 0;
  itr = client_list;
  while (itr != NULL)
  {
    ++i;
    itr = itr->next;
  }
  return (i);

}
