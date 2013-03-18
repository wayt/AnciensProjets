/*
** do_shell_bin_utils.c for do in /home/fest/Epitech/Minishell2/do
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 30 16:01:34 2012 maxime ginters
** Last update Fri Nov 30 16:45:03 2012 maxime ginters
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

void	mod_output(t_command *cmd)
{
  int	fd;
  int	open_flags;

  open_flags = O_WRONLY | O_CREAT;
  open_flags |= cmd->output_type == OUTPUT_APPEND ? O_APPEND : O_TRUNC;
  if ((fd = open(cmd->output_file, open_flags, 0644)) == -1)
  {
    my_printf("Error: fail to open %s\n", cmd->output_file);
    exit(1);
  }
  if (dup2(fd, 1) == -1)
  {
    my_printf("Error: fail to dup fd...\n");
    exit(1);
  }
  safe_close(fd);
}

void	mod_input(t_command *cmd)
{
  int	fd;

  if ((fd = open(cmd->input_file, O_RDONLY)) == -1)
  {
    my_printf("Error: fail to open %s\n", cmd->input_file);
    exit(1);
  }
  if (dup2(fd, 0) == -1)
  {
    my_printf("Error: fail to dup fd...\n");
    exit(1);
  }
  safe_close(fd);
}
