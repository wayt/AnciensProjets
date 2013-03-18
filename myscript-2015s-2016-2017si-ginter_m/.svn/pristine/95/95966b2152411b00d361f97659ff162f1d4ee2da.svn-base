/*
** my_libc.c for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Feb 27 13:45:44 2013 maxime ginters
** Last update Wed Feb 27 16:33:03 2013 maxime ginters
*/

#include "my_libc.h"

int	my_openpty(int *amaster, int *aslave)
{
  char	*name;

  if ((*amaster = open("/dev/ptmx", O_RDWR)) > 0)
  {
    my_unlockpt(*amaster);
    if ((name = my_ptsname(*amaster)) == 0)
      return (xperror());
    if ((*aslave = open(name, O_RDWR)) == 0)
      xperror();
    my_grantpt(*aslave);
    free(name);
    return (0);
  }
  return (xperror());
}

int	my_forkpty(int *amaster, struct winsize *win)
{
  int	master;
  int	slave;
  int	pid;

  (void)win;

  if (my_openpty(&master, &slave) == -1)
    return (-1);

  pid = fork();
  if (pid == -1)
    return (xperror());
  if (pid == 0)
  {
    close(master);
    if (my_login_tty(slave) == -1)
      exit(1);
    return (0);
  }
  else
  {
    *amaster = master;
    close(slave);
    return (pid);
  }
}
