/*
** do_setenv.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:41:00 2012 maxime ginters
** Last update Sat Nov 10 16:50:00 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "chaine.h"
#include "mysh.h"

char	*trim_quote(char *str)
{
  int	size;

  size = my_strlen(str) - 1;
  if ((str[0] == '\'' && str[size] == '\'') ||
    (str[0] == '"' && str[size] == '"'))
    return (my_substr(str, 1, size - 1));
  return (my_strdup(str));
}

void	do_setenv(char **t, t_env *env)
{
  t_env_node	*node;
  char	*value;
  int	i;

  if (t[1] == NULL || t[2] == NULL)
    return;
  i = 3;
  value = my_strdup(t[2]);
  while (t[i] != NULL)
  {
    value = my_strcat(value, my_strdup(" "));
    value = my_strcat(value, my_strdup(t[i++]));
  }
  value = trim_quote(value);
  node = find_node(env->list, t[1]);
  if (node == NULL)
    node = append_new(env->list, t[1], value);
  else
    update_value(env->list, t[1], value);
  if (env->list == NULL)
    env->list = node;
  clean_wordtab(env->environ);
  env->environ = convert_to_tab(env->list);
  free(value);
}
