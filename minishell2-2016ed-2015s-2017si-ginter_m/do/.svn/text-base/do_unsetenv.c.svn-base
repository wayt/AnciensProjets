/*
** do_unsetenv.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:59:36 2012 maxime ginters
** Last update Thu Nov 29 13:59:40 2012 maxime ginters
*/

#include "my.h"
#include "chaine.h"
#include "env_functions.h"
#include "mysh.h"

int	do_unsetenv(t_command *t, t_env *env)
{
  if (t->commands[0][1] == NULL)
    return (1);
  if (my_strcmp_casse(t->commands[0][1], "*") == 0)
    clean_list(&env->list);
  else
    delete_entry(&env->list, t->commands[0][1]);
  clean_wordtab(env->environ);
  env->environ = convert_to_tab(env->list);
  return (0);
}
