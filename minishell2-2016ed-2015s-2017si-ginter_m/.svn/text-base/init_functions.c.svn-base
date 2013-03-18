/*
** init_functions.c for Minishell2 in /home/fest/Epitech/Minishell2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 27 15:17:32 2012 maxime ginters
** Last update Tue Nov 27 15:55:10 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "env_functions.h"
#include "chaine.h"

int	init_env(t_env *env)
{
  env->username = find_value(env->list, "USERNAME");
  env->pwd = find_value(env->list, "PWD");
  env->home = find_value(env->list, "HOME");
  if (env->username == NULL || env->pwd == NULL || env->home == NULL)
    return (0);
  return (1);
}

void	set_pwd(t_env *env, char *value)
{
  free(env->pwd);
  env->pwd = my_strdup(value);
  create_or_update_value(env, "PWD", value);
}
