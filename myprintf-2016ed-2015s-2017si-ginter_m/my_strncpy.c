/*
** my_strncpy.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 09:31:50 2012 maxime ginters
** Last update Tue Oct 09 11:35:28 2012 maxime ginters
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0' && i < n)
  {
    *(dest + i) = *(src + i);
    ++i;
  }
  while (i < n)
    *(dest + i++) = '\0';
  return (dest);
}
