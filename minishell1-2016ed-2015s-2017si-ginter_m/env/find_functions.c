/*
** find_functions.c for env in /home/fest/Epitech/MiniShell1/env
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 15:47:48 2012 maxime ginters
** Last update Fri Nov 09 12:49:57 2012 maxime ginters
*/

#include "my.h"
#include "chaine.h"
#include "env_functions.h"

t_env_node	*find_node(t_env_node *list, char *name)
{
  while (list != NULL)
  {
    if (my_strcmp_casse(list->name, name) == 0)
      return (list);
    list = list->next;
  }
  return (NULL);
}

char	*find_value(t_env_node *list, char *name)
{
  while (list != NULL)
  {
    if (my_strcmp_casse(list->name, name) == 0)
      return (my_strdup(list->value));
    list = list->next;
  }
  return (NULL);
}
