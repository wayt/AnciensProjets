/*
** main.c for re-code-my_ls in /home/fest/Epitech/re-code-my_ls
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Nov 09 15:32:21 2012 maxime ginters
** Last update Fri Nov 09 15:35:47 2012 maxime ginters
*/

#include <sys/types.h>
#include <dirent.h>

#ifndef NULL
  #define NULL 0x0
#endif

void	my_putstr(char *str)
{
  if (!str)
    return;

  while (*str != '\0')
    write(1, str++, 1);
}

int	main()
{
  DIR	*dir;
  struct dirent	*drt;

  dir = opendir(".");
  if (dir != NULL)
  {
    while ((drt = readdir(dir)) != NULL)
    {
      my_putstr(drt->d_name);
      my_putstr("\n");
    }
    closedir(dir);
  }
  else
    my_putstr("Erreur ouverture du dossier\n");
  return (0);
}
