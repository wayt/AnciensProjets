/*
** mysh.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:31:32 2012 maxime ginters
** Last update Sat Nov 10 17:11:37 2012 maxime ginters
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "mysh.h"
#include "env_functions.h"
#include "chaine.h"

int	mysh(char **environ)
{
  int	read_size;
  char	buffer[4096];
  char	*username;
  t_env	*env;

  env = create_environ(environ);
  if ((env->username = find_value(env->list, "USERNAME")) == NULL)
  {
    my_putstr("Fail to get username\n");
    exit(1);
  }
  my_putstr("Welcome to mysh\n");
  my_memset(buffer, 0x0, 4096);
  print_prompt(env);
  read_size = read(0, buffer, 4096);
  while (read_size > 0)
  {
    buffer[read_size - 1] = '\0';
    exec_command(my_strdup(buffer), env);
    my_memset(buffer, 0x0, 4096);
    print_prompt(env);
    read_size = read(0, buffer, 4096);
  }
  free_full_env(env);
  return (0);
}

void	exec_command(char *command, t_env *env)
{
  char	**t = my_str_to_wordtab_sep(command, ' ');
  free(command);
  if (my_strcmp_casse(t[0], "exit") == 0)
    do_exit(t, env);
  else if (my_strcmp_casse(t[0],  "env") == 0)
    do_env(t, env);
  else if (my_strcmp_casse(t[0], "setenv") == 0)
    do_setenv(t, env);
  else if (my_strcmp_casse(t[0], "unsetenv") == 0)
    do_unsetenv(t, env);
  else if (my_strcmp_casse(t[0], "cd") == 0)
    do_cd(t, env);
  else
    exec_shell_bin(t, env);
  clean_wordtab(t);
}

void	print_prompt(t_env *env)
{
  my_putstr("[#");
  if (env->username != NULL)
    my_putstr(env->username);
  my_putstr("#]$ ");
}

void	exec_shell_bin(char **t, t_env *env)
{
  int	fk;
  int	status;
  char	*path;
  char	buffer[4096];

  my_memset(buffer, 0x0, 4096);
  fk = fork();
  if (fk == 0)
  {
    path = comput_path(env->list, t[0]);
    if (my_strlen(path) > 4095)
      exit(0);
    my_strcpy(buffer, path);
    free(path);
    if (access(buffer, X_OK) != 0)
      my_put_triple_str("Error : ", t[0], ": Command no found\n");
    else
      execve(buffer, t, env->environ);
    exit(0);
  }
  else
    wait(&status);
}
