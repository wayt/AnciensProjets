/*
** do_exit.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:30:18 2012 maxime ginters
** Last update Sat Nov 10 16:46:11 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void	do_exit(char **t, t_env *env)
{
  clean_wordtab(t);
  my_put_triple_str("Bye bye ", env->username, " !\n");
  free_full_env(env);
  exit(0);
}
