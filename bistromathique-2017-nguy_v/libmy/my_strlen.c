/*
** my_strlen.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:22:42 2012 maxime ginters
** Last update Tue Oct 09 11:23:37 2012 maxime ginters
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    ++i;
  return (i);
}
