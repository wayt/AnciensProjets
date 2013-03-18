/*
** do_exit.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:30:18 2012 maxime ginters
** Last update Fri Nov 30 19:23:02 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int	do_exit(t_command *t, t_env *env)
{
  (void)t;
  my_put_triple_str("Bye bye ", env->username, " !\n");
  free_full_env(env);
  exit(0);
  return (0);
}
