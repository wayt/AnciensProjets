/*
** do_shell_bin.c for do in /home/fest/Epitech/Minishell2/do
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Nov 29 14:34:27 2012 maxime ginters
** Last update Fri Nov 30 19:27:22 2012 maxime ginters
*/

#include <sys/wait.h>
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

#define CMD_C t->command_count

int	create_path(char *cmd, t_env *env, char buffer[4096])
{
  char	*path;

  my_memset(buffer, 0x0, 4096);
  path = comput_path(env->list, cmd);
  if (my_strlen(path) > 4095)
    return (0);
  my_strcpy(buffer, path);
  free(path);
  if (access(buffer, X_OK) != 0)
  {
    my_printf("Error: %s: Command no found\n", cmd);
    return (0);
  }
  return (1);
}

int	close_pipefd(int pipefd[2][2])
{
  safe_close(pipefd[0][0]);
  safe_close(pipefd[0][1]);
  safe_close(pipefd[1][0]);
  safe_close(pipefd[1][1]);
  return (0);
}

void	create_pipe_redirect(int pipefd[2][2], t_command *t, int i, int curr)
{
  if (i == t->command_count - 1 && t->output_file)
    mod_output(t);
  if (i == 0 && t->input_file)
    mod_input(t);
  safe_close(pipefd[curr][0]);
  safe_close(pipefd[!curr][1]);
  if (t->command_count > 1 && i < t->command_count - 1)
  {
    if (dup2(pipefd[curr][1], 1) == -1)
      exit_error("Error: fail to dup2 the pipe\n");
    else
      safe_close(pipefd[curr][1]);
  }
  if (t->command_count > 1 && i > 0)
  {
    if (dup2(pipefd[!curr][0], 0) == -1)
      exit_error("Error: fail to dup2 the pipe to 0\n");
    else
      safe_close(pipefd[!curr][0]);
  }
}

void	init_pipe(int pipefd[2][2], int i[2])
{
  pipefd[0][0] = 0;
  pipefd[0][1] = 0;
  pipefd[1][0] = 0;
  pipefd[1][1] = 0;
  my_memset(i, 0, 2 * sizeof(int));
}

int	do_shell_bin(t_command *t, t_env *env)
{
  char	buffer[4096];
  int	i[2];
  int	pipefd[2][2];

  init_pipe(pipefd, i);
  while (i[0] < t->command_count)
    if (create_path(t->commands[i[0]][0], env, buffer) == 1)
    {
      if (CMD_C > 1 && i[0] != CMD_C - 1 && pipe(pipefd[i[1]]) == -1)
          return (my_printf("Error: fail to create pipe...\n"));
      safe_close(pipefd[!i[1]][1]);
      if (fork() == 0)
      {
        create_pipe_redirect(pipefd, t, i[0], i[1]);
        execve(buffer, t->commands[i[0]], env->environ);
        exit(1);
      }
      else
        wait(NULL);
      i[1] = !i[1];
      ++i[0];
    }
    else
      return (1);
  return (close_pipefd(pipefd));
}
