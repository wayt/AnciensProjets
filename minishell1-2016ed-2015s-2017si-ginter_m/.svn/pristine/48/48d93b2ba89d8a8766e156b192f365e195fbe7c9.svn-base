/*
** mod_functions.c for env in /home/fest/Epitech/MiniShell1/env
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:45:44 2012 maxime ginters
** Last update Sat Nov 10 17:00:44 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "chaine.h"
#include "env_functions.h"

void	update_value(t_env_node *list, char *name, char *newvalue)
{
  t_env_node	*node;

  node = find_node(list, name);
  if (node == NULL)
    return;
  free(node->value);
  node->value = my_strdup(newvalue);
}

void	delete_entry(t_env_node **list, char *name)
{
  t_env_node	*prev;
  t_env_node	*itr;

  prev = NULL;
  itr = *list;
  while (itr != NULL)
  {
    if (my_strcmp_casse(itr->name, name) == 0)
    {
      free(itr->name);
      free(itr->value);
      if (prev != NULL)
        prev->next = itr->next;
      else
        *list = itr->next;
      free(itr);
      return;
    }
    prev = itr;
    itr = itr->next;
  }
}

void	clean_list(t_env_node **list)
{
  t_env_node	*tmp;

  while (*list != NULL)
  {
    tmp = *list;
    free(tmp->name);
    free(tmp->value);
    *list = tmp->next;
    free(tmp);
  }
}

void	free_full_env(t_env *env)
{
  clean_list(&env->list);
  clean_wordtab(env->environ);
  free(env->username);
  free(env);
}
