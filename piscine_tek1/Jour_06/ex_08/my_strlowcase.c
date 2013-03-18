/*
** my_strlowcase.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 11:34:13 2012 maxime ginters
** Last update Mon Oct 08 13:27:35 2012 maxime ginters
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
  {
    if (*(str + i) >= 'A' && *(str + i) <= 'Z')
      *(str + i) += 'a' - 'A';
    ++i;
  }

  return (str);
}
