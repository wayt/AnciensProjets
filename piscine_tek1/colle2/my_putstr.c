/*
** my_putstr.c for colle2 in /home/ginter_m/colle2
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 13 12:14:44 2012 maxime ginters
** Last update Sun Oct 14 16:59:08 2012 maxime ginters
*/

void	my_putstr(char *str)
{
  int	i;

  if (!str)
    return;

  i = 0;
  while (str[i] != '\0')
    write(1, str + i++, 1);
}
