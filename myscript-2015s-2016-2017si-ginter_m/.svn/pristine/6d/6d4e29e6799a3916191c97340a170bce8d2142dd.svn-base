/*
** my_libc2.c for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Feb 27 16:32:17 2013 maxime ginters
** Last update Wed Feb 27 16:32:55 2013 maxime ginters
*/

#include <errno.h>
#include <grp.h>
#include "my_libc.h"

int	xperror()
{
  perror(strerror(errno));
  exit(1);
  return (-1);
}

int	my_login_tty(int fd)
{
  if (setsid() < 0)
    return (xperror());
  if (ioctl(fd, TIOCSCTTY, 1) < 0)
    return (xperror());
  dup2(fd, 0);
  dup2(fd, 1);
  dup2(fd, 2);
  if (fd > 2)
    close(fd);
  return (0);
}

int	my_grantpt(int fd)
{
  struct group	*grp;

  if (fchmod(fd, 0620) == -1)
    return (xperror());
  grp = getgrnam("tty");
  if (grp == NULL)
    return (xperror());
  if (fchown(fd, getuid(), grp->gr_gid) == -1)
    return (xperror());
  return (0);
}

int	my_unlockpt(int fd)
{
  int	truc_qui_sert_a_rien;

  truc_qui_sert_a_rien = 0;
#ifdef TIOCSPTLCK
  if (ioctl(fd, TIOCSPTLCK, &truc_qui_sert_a_rien) < 0)
    return (xperror());
#endif
  return 0;
}

char*	my_ptsname(int fd)
{
  int	id;
  char	name[16];

  if (ioctl(fd, TIOCGPTN, &id) < 0)
    exit(1);
  sprintf(name, "/dev/pts/%d", id);
  if (access(name, F_OK) == -1)
    return (NULL);
  return strdup(name);
}
