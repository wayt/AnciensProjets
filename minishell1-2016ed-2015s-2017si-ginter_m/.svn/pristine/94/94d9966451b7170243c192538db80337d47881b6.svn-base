/*
** my_strncat.c for ex_01 in /home/ginter_m/Jour_07/ex_01
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 13:25:22 2012 maxime ginters
** Last update Tue Oct 09 13:44:51 2012 maxime ginters
*/

int	my_strlen(char *);

char	*my_strncat(char *dest, char *src, int nb)
{
  int	size;
  int	i;

  size = my_strlen(dest);
  i = 0;
  while (i < nb && *(src + i) != '\0')
    *(dest + size + i) = *(src + i++);
  *(dest + size + i) = '\0';
  return (dest);
}
