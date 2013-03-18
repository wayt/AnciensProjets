/*
** my_putstr.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:46:05 2012 maxime ginters
** Last update Mon Oct 08 13:50:26 2012 maxime ginters
*/

int	my_putstr(char *str)
{
  int	i;

  if (!str)
    return (0);

  i = 0;
  while (*(str + i) != '\0')
    write(1, str + i++, 1);

  return (0);
}
