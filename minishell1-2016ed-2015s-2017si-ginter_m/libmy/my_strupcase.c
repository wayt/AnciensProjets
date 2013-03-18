/*
** my_strupcase.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 11:28:34 2012 maxime ginters
** Last update Tue Oct 09 11:49:37 2012 maxime ginters
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
  {
    my_upperize(str + i);
    ++i;
  }
  return (str);
}
