/*
** my_libc.h for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Feb 27 14:20:55 2013 maxime ginters
** Last update Wed Feb 27 16:33:44 2013 maxime ginters
*/

#ifndef MY_LIBC_H_
# define MY_LIBC_H_

#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <sys/types.h>

int	my_grantpt(int fd);
int	my_unlockpt(int fd);
char	*my_ptsname(int fd);
int	my_openpty(int *amaster, int *aslave);
int	my_forkpty(int *amaster, struct winsize *win);
int	my_login_tty(int fd);
int	xperror();

#endif /* !MY_LIBC_H_ */
