/*
** main.c for corewar in /home/leroy_v/Epitech/corewar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mon Dec 03 15:09:52 2012 vincent leroy
** Last update Fri Dec 14 13:42:18 2012 vincent leroy
*/

#include "asm.h"

char	*verif_error(int *fd, char *av)
{
  char	*name;

  if ((name = verif_name_file(av)) == NULL)
    error(INPUT_ERROR, 1);
  if ((*fd = open(av, O_RDONLY)) == -1)
    string_error(FILE_ERROR, av, 1);
  return (name);
}

int	main(int ac, char **av)
{
  int	i;
  int	fd;
  char	*name;

  if (ac < 2)
    error(INPUT_ERROR, 1);
  i = 1;
  while (i < ac)
  {
    name = verif_error(&fd, av[i]);
    my_printf("Assembling %s:\n", av[i]);
    compile(fd, name);
    close(fd);
    free(name);
    i++;
  }
  return (0);
}
