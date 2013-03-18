/*
** do_unsetenv.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:59:36 2012 maxime ginters
** Last update Sat Nov 10 16:50:09 2012 maxime ginters
*/

#include "my.h"
#include "chaine.h"
#include "env_functions.h"
#include "mysh.h"

void	do_unsetenv(char **t, t_env *env)
{
  if (t[1] == NULL)
    return;
  if (my_strcmp_casse(t[1], "*") == 0)
    clean_list(&env->list);
  else
    delete_entry(&env->list, t[1]);
  clean_wordtab(env->environ);
  env->environ = convert_to_tab(env->list);
}
