/*
** my_super_putstr.c for cat in /home/fest/Epitech/Jour_13/cat
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 18:36:48 2012 maxime ginters
** Last update Thu Oct 25 18:43:37 2012 maxime ginters
*/

void	my_super_putstr(char *str, int max_size)
{
  int	i;

  i = 0;
  while (i < max_size)
    write(1, str + i++, 1);
}
