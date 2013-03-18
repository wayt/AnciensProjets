/*
** core.h for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 11 17:48:34 2013 maxime ginters
** Last update Thu Feb 28 14:54:21 2013 maxime ginters
*/

#ifndef CORE_H_
# define CORE_H_

#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "params_parser.h"
#include "my_libc.h"

void	run(t_params const* params);

void	remove_block(int fd1, int fd2);
void	init_term(struct termios* term);
void	restore_term(struct termios* term);

#endif /* !CORE_H_ */
