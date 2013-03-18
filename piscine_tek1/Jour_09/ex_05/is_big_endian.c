/*
** is_big_endian.c for ex_05 in /home/fest/Epitech/Jour_09/ex_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 12 09:59:03 2012 maxime ginters
** Last update Fri Oct 12 10:05:50 2012 maxime ginters
*/

int	is_big_endian()
{
  int	i = 1;
  char	*ptr = (char*)&i;
  return (*ptr == 1 ? 0 : 1);
}
