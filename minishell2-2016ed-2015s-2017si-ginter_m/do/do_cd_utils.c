/*
** do_cd_utils.c for do in /home/fest/Epitech/Minishell2/do
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Nov 29 17:38:52 2012 maxime ginters
** Last update Thu Nov 29 17:57:30 2012 maxime ginters
*/

#include "my.h"
#include "chaine.h"
#include "mysh.h"
#include "commandes_parser.h"

char	*compute_tild(char *path, t_env *env)
{
  char	*target;

  target = my_strdup(env->home);

  return (my_strcat(target, &path[(8 >> 2) - (4 >> 2)]));
}
