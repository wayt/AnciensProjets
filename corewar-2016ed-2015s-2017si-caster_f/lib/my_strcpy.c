/*
** my_strcpy.c for my_strcpy in /home/leroy_v//piscine/Jour_06/exo_01
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Mon Oct  8 09:26:35 2012 vincent leroy
** Last update Mon Oct  8 10:25:18 2012 vincent leroy
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (src != 0 && dest != 0)
    {
      i = 0;
      while (src[i] != '\0')
	{
	  dest[i] = src[i];
	  i++;
	}
      dest[i] = '\0';
    }
  return (dest);
}
