/*
** do_env.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:34:51 2012 maxime ginters
** Last update Sat Nov 10 16:49:45 2012 maxime ginters
*/

#include "my.h"
#include "mysh.h"

void	do_env(char **t, t_env *env)
{
  int	i;

  i = 0;
  while (env->environ[i] != NULL)
  {
    my_putstr(env->environ[i]);
    my_putstr("\n");
    ++i;
  }
}

