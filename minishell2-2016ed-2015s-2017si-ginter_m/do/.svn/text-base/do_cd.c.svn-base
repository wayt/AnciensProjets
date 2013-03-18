/*
** do_cd.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 10 14:20:45 2012 maxime ginters
** Last update Fri Nov 30 19:24:09 2012 maxime ginters
*/

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "my.h"
#include "chaine.h"
#include "mysh.h"
#include "commandes_parser.h"

int	check_target(char *target)
{
  if (target == NULL)
  {
    my_perror("Error: can't get home directory from environement\n");
    return (0);
  }
  if (my_strcmp_casse(target, "") == 0)
  {
    my_perror("Error: can't do that now...\n");
    free(target);
    return (0);
  }
  if (chdir(target) < 0)
  {
    my_perror("Error: fail chdir(), give us errno to more informations...\n");
    return (0);
  }
  return (1);
}

char	*remove_last_slash(char *str)
{
  int	i;
  int	last;

  if (my_strcmp_casse(str, "/") == 0)
    return (str);
  i = 0;
  last = 0;
  while (str[i] != '\0')
  {
    if (str[i] ==  '/')
      last = i;
    ++i;
  }
  if (last == 0)
    return (my_strdup("/"));
  return (my_substr(str, 0, last - 1));
}

char	*mod_pwd(char *pwd, char *path)
{
  char	**t;
  int	i;

  if (path[0] == '/')
    return (path);
  t = my_str_to_wordtab_sep(path, '/');
  i = 0;
  while (t[i])
  {
    if (my_strcmp_casse(t[i], "..") == 0)
      pwd = remove_last_slash(pwd);
    else if (my_strcmp_casse(t[i], ".") != 0)
    {
      if (pwd[my_strlen(pwd) - 1] != '/')
        pwd = my_strcat(pwd, "/");
      pwd = my_strcat(pwd, t[i]);
    }
    ++i;
  }
  return (pwd);
}

void	update_old_pwd(t_env* env)
{
  if (env->_olddir)
    free(env->_olddir);
  env->_olddir = my_strdup(env->pwd);
  create_or_update_value(env, "_OLDDIR", env->_olddir);
}

int	do_cd(t_command *t, t_env *env)
{
  char	*target;
  char	*pwd;

  pwd = my_strdup(env->pwd);
  target = NULL;
  if (t->commands[0][1] == NULL)
    target = my_strdup(env->home);
  else if (t->commands[0][1][0] == '~')
    target = compute_tild(t->commands[0][1], env);
  else if (my_strcmp_casse(t->commands[0][1], "-") == 0)
    target = my_strdup(env->_olddir);
  else
    target = mod_pwd(pwd, my_strdup(t->commands[0][1]));
  if (check_target(target) == 1)
  {
    update_old_pwd(env);
    set_pwd(env, target);
    free(target);
  }
  return (0);
}
