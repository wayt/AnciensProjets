/*
** mysh.h for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:31:27 2012 maxime ginters
** Last update Fri Nov 30 19:30:35 2012 maxime ginters
*/

#ifndef MYSH_H_
# define MYSH_H_

#include "chaine.h"
#include "commandes_parser.h"

/*
** mysh.c
*/
int	mysh(char **environ);
void	exec_command(char *command, t_env *env);
void	print_prompt(t_env *env);


/*
** do_shell_bin.c
*/
int	do_shell_bin(t_command *t, t_env *env);

/*
** do_shell_bin_utils.c
*/
void	mod_output(t_command *cmd);
void	mod_input(t_command *cmd);

/*
** do_exit.c
*/
int	do_exit(t_command *t, t_env *env);

/*
** do_env.c
*/
int	do_env(t_command *t, t_env *env);
int	do_dumpenv(t_command *t, t_env *env);

/*
** do_setenv.c
*/
int	do_setenv(t_command *t, t_env *env);

/*
** do_unsetenv.c
*/
int	do_unsetenv(t_command *t, t_env *env);

/*
** do_cd.c
*/
int	do_cd(t_command *t, t_env *env);

/*
** do_cd_utils.c
*/
char	*compute_tild(char *path, t_env *env);

struct s_mysh_command
{
  char	*cmd;
  int	(*funct)(t_command*, t_env*);
};

typedef struct s_mysh_command t_mysh_command;

extern t_mysh_command	mysh_commands[];

#endif /* !MYSH_H_ */
