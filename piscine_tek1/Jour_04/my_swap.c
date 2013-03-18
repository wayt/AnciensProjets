/*
** my_swap.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 08:56:17 2012 maxime ginters
** Last update Tue Oct 09 10:19:43 2012 maxime ginters
*/

void	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
