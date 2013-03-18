/*
** my_strncpy.c for my_strncpy in /home/leroy_v//piscine/Jour_06/exo_02
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Mon Oct  8 09:33:59 2012 vincent leroy
** Last update Sat Nov 17 10:40:44 2012 leroy_v
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  if (dest == 0 || src == 0)
    return (0);
  i = 0;
  while (i < n && src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  if (src[i] == '\0')
    dest[i] = '\0';
  return (dest);
}
