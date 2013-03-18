/*
** my_strlen.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 09:05:47 2012 maxime ginters
** Last update Tue Oct 09 10:20:57 2012 maxime ginters
*/

int	my_strlen(char *str)
{
  int	count;
  int	offset;

  count = 0;
  offset = 0;
  while (*(str + offset++) != '\0')
    ++count;
  return count;
}
