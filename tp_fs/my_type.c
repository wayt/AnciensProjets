/*
** my_type.c for tp_fs in /home/fest/Epitech/tp_fs
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 29 14:22:50 2012 maxime ginters
** Last update Mon Oct 29 14:56:49 2012 maxime ginters
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef NULL
  #define NULL 0x0
#endif

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

int	main(int ac, char **av)
{
  struct stat	sb;

  if (ac < 2)
    return (1);
  if (lstat(av[1], &sb) < 0)
  {
    my_putstr("Failed read\n");
    return (1);
  }

  if (S_ISDIR(sb.st_mode))
    my_putstr("Directory\n");
  else if (S_ISLNK(sb.st_mode))
    my_putstr("Symbolic link\n");
  else if (S_ISREG(sb.st_mode))
    my_putstr("File\n");

  return (0);
}
