/*
** mysh.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:31:32 2012 maxime ginters
** Last update Fri Nov 30 19:30:08 2012 maxime ginters
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "mysh.h"
#include "env_functions.h"
#include "chaine.h"
#include "commandes_parser.h"

t_mysh_command	mysh_commands[] = {
  {"exit", do_exit},
  {"env", do_env},
  {"setenv", do_setenv},
  {"unsetenv", do_unsetenv},
  {"cd", do_cd},
  {"dumpenv", do_dumpenv},
  {NULL, do_shell_bin}
};

void	handle_null(int num)
{
  signal(num, &handle_null);
  write(1, "\n", 1);
}

int	mysh(char **environ)
{
  int	read_size;
  char	buffer[4096];
  t_env	*env;

  env = create_environ(environ);
  if (init_env(env) == 0)
    exit_error("Fail to init env, you need at least HOME, USERNAME and PWD\n");
  my_putstr("Welcome to mysh\n");
  my_memset(buffer, 0x0, 4096);
  print_prompt(env);
  signal(SIGINT, &handle_null);
  read_size = read(0, buffer, 4096);
  while (read_size != 0)
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
  int	i;
  t_command_node	*t;
  t_command_node	*first;

  t = create_commands(my_trim(command));
  first = t;
  while (t)
  {
    i = 0;
    while (mysh_commands[i].cmd != NULL && i != -1)
    {
      if (my_strcmp_casse(t->cmd->commands[0][0], mysh_commands[i].cmd) == 0)
      {
        (mysh_commands[i].funct)(t->cmd, env);
        i = -1;
      }
      else
        ++i;
    }
    if (i != -1)
      (mysh_commands[i].funct)(t->cmd, env);
    t = t->next;
  }
  free_commands(first);
}

void	print_prompt(t_env *env)
{
  int	i;
  int	at;

  i = 0;
  at = 0;
  while (env->pwd[i] != '\0')
    if (env->pwd[i++] == '/')
      at = i - 1;
  my_printf("[#%s:%s#]$ ", env->username, &env->pwd[at == 0 ? at : at + 1]);
}

