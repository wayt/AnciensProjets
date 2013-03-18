/*
** my_files.c for tp_fs in /home/fest/Epitech/tp_fs
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 29 14:22:50 2012 maxime ginters
** Last update Mon Oct 29 14:28:15 2012 maxime ginters
*/

#include <dirent.h>

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
  struct dirent	*drt;
  DIR	*dirid;

  dirid = opendir(".");
  if (dirid != NULL)
  {
    while ((drt = readdir(dirid)) > 0)
    {
      my_putstr(drt->d_name);
      my_putstr("\n");
    }
  }
}
