/*
** do_cd.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 10 14:20:45 2012 maxime ginters
** Last update Sat Nov 10 16:49:37 2012 maxime ginters
*/

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "my.h"
#include "chaine.h"
#include "mysh.h"

void	check_target(char *target)
{
  if (target == NULL)
    my_perror("Error: can't get home directory from environement\n");
}

void	do_cd(char **t, t_env *env)
{
  char	*target;

  target = NULL;
  if (t[1] == NULL || my_strcmp_casse(t[1], "~") == 0)
    target = find_value(env->list, "HOME");
  else
    target = my_strdup(t[1]);
  check_target(target);

  if (chdir(target) < 0)
    my_perror("Error: fail chdir(), give us errno to more informations...\n");
  free(target);
}
