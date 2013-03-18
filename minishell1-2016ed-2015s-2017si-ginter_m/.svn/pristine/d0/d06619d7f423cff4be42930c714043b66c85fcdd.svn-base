/*
** mysh.h for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:31:27 2012 maxime ginters
** Last update Sat Nov 10 16:47:46 2012 maxime ginters
*/

#ifndef MYSH_H_
# define MYSH_H_

#include "chaine.h"

/*
** mysh.c
*/
int	mysh(char **environ);
void	exec_command(char *command, t_env *env);
void	print_prompt(t_env *env);
void	exec_shell_bin(char **t, t_env *env);

/*
** do_exit.c
*/
void	do_exit(char **t, t_env *env);

/*
** do_env.c
*/
void	do_env(char **t, t_env *env);

/*
** do_setenv.c
*/
void	do_setenv(char **t, t_env *env);

/*
** do_unsetenv.c
*/
void	do_unsetenv(char **t, t_env *env);

/*
** do_cd.c
*/
void	do_cd(char **t, t_env *env);

#endif /* !MYSH_H_ */
