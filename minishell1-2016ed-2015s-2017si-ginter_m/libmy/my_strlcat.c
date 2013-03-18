/*
** my_strlcat.c for ex_01 in /home/ginter_m/Jour_07/ex_01
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 13:46:59 2012 maxime ginters
** Last update Tue Oct 09 13:59:22 2012 maxime ginters
*/

int	my_strlen(char *);

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	dest_size;

  dest_size = my_strlen(dest);
  i = 0;
  while (i + dest_size < size && *(src + i) != '\0')
    *(dest + i + dest_size) = *(src + i++);
  *(dest + i + dest_size) = '\0';
  return (size);
}
