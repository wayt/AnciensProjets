/*
** create_functions.c for chaine in /home/fest/Epitech/MiniShell1/chaine
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 15:21:39 2012 maxime ginters
** Last update Sat Nov 10 16:26:03 2012 maxime ginters
*/

#include "my.h"
#include "chaine.h"
#include "env_functions.h"

t_env	*create_environ(char **env)
{
  t_env	*stc;
  int	i;
  int	tmp;

  stc = xmalloc(sizeof(t_env));
  stc->list = create_from_tab(env);
  stc->environ = xmalloc(sizeof(char*));
  i = 0;
  while (env[i] != NULL)
  {
    tmp = (i + 1) * sizeof(char*);
    stc->environ = my_realloc(stc->environ, i + 2, sizeof(char*), tmp);
    stc->environ[i] = my_strdup(env[i]);
    ++i;
  }
  stc->environ[i] = NULL;
  return (stc);
}

t_env_node	*create_from_tab(char	**env)
{
  int	i;
  t_env_node	*new;
  t_env_node	*first;
  t_env_node	*prev;

  new = NULL;
  first = NULL;
  prev = NULL;
  i = 0;
  while (env[i] != NULL)
  {
    new = xmalloc(sizeof(t_env_node));
    new->name = get_field_name(env[i]);
    new->value = get_field_value(env[i]);
    new->next = NULL;
    if (first == NULL)
      first = new;
    if (prev != NULL)
      prev->next = new;
    prev = new;
    ++i;
  }
  return (first);
}

t_env_node	*append_new(t_env_node *list, char *name, char *value)
{
  t_env_node	*node;

  node = xmalloc(sizeof(t_env_node));
  node->name = my_strdup(name);
  node->value = my_strdup(value);
  node->next = NULL;

  if (list != NULL)
  {
    while (list->next != NULL)
      list = list->next;
    list->next = node;
  }
  return (node);
}

char	**convert_to_tab(t_env_node *list)
{
  int	row;
  char	**t;

  t = xmalloc(1 * sizeof(char*));
  row = 0;
  while (list != NULL)
  {
    t = my_realloc(t, row + 2, sizeof(char*), (row + 1) * sizeof(char*));
    t[row] = my_strdup(list->name);
    t[row] = my_strcat(t[row], "=");
    if (list->value != NULL)
      t[row] = my_strcat(t[row], list->value);
    ++row,
    list = list->next;
  }
  t[row] = NULL;
  return (t);
}
