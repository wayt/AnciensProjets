/*
** name.c for asm in /home/leroy_v/Epitech/corewar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mon Dec 03 16:33:59 2012 vincent leroy
** Last update Tue Dec 04 17:55:21 2012 vincent leroy
*/

#include "asm.h"

char	*get_name_file(char *name)
{
  char	*n;
  int	index;
  int	i;

  index = my_strlen(name) - 1;
  if ((n = my_malloc(index + 5, MALLOC_ERROR)) == NULL)
    exit(1);
  while (index >= 0 && name[index] != '.')
    index--;
  i = 0;
  while (name[i] != '\0' && i < index)
  {
    n[i] = name[i];
    i++;
  }
  my_strcat(n, ".cor");
  return (n);
}

char	*verif_name_file(char *name)
{
  int	i;

  i = my_strlen(name) - 1;
  while (i >= 0 && name[i] != '.' && name[i] != '/')
    i--;
  if (i < 0 || name[i] == '/')
    return (get_name_file(name));
  if (name[i + 1] != '\0' && name[i + 1] == 's' && name[i + 2] == '\0')
    return (get_name_file(name));
  return (NULL);
}
