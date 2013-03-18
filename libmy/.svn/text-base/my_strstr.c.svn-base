/*
** my_strstr.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 10:18:45 2012 maxime ginters
** Last update Tue Oct 09 11:41:43 2012 maxime ginters
*/

#ifndef MY_NULL
  #define MY_NULL 0x0
#endif

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  char	*retour;

  i = 0;
  j = 0;
  retour = MY_NULL;
  while (*(str + i) != '\0' && *(to_find + j) != '\0')
  {
    if (*(str + i) == *(to_find + j))
    {
      retour = str + i - j;
      ++j;
    }
    else
    {
      j = 0;
      retour = MY_NULL;
    }
    ++i;
  }
  if (retour != MY_NULL && *(str + i) == '\0' && *(to_find + j) != '\0')
    retour = MY_NULL;
  return (retour);
}

