/*
** my_strcpy.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 09:20:14 2012 maxime ginters
** Last update Fri Oct 26 18:30:19 2012 maxime ginters
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0')
  {
    *(dest + i) = *(src + i);
    ++i;
  }

  *(dest + i) = '\0';

  return (dest);
}
