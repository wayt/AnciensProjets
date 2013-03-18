/*
** my_strlen.c for bcpe042colle3-2017-ginter_m in /home/paquit_l/bcpe042colle3-2017-ginter_m
** 
** Made by lauris paquit
** Login   <paquit_l@epitech.eu>
** 
** Started on  Sat Oct 27 20:55:30 2012 lauris paquit
** Last update Sat Oct 27 21:49:48 2012 maxime ginters
*/

int	my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
