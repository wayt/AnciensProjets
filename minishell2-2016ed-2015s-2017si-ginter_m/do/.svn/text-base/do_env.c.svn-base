/*
** do_env.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:34:51 2012 maxime ginters
** Last update Fri Nov 30 19:23:33 2012 maxime ginters
*/

#include "my.h"
#include "mysh.h"
#include "commandes_parser.h"

int	do_env(t_command *t, t_env *env)
{
  int	i;

  (void)t;
  i = 0;
  while (env->environ[i] != NULL)
  {
    my_putstr(env->environ[i]);
    my_putstr("\n");
    ++i;
  }
  return (0);
}

int	do_dumpenv(t_command *t, t_env *env)
{
  (void)t;
  my_printf("username : %s\n", env->username);
  my_printf("    home : %s\n", env->home);
  my_printf("     pwd : %s\n", env->pwd);
  my_printf(" _olddir : %s\n", env->_olddir);
  return (0);
}
