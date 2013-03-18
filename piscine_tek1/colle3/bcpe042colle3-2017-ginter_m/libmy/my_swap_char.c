/*
** my_swap_char.c for temp_lib in /home/ginter_m/temp_lib
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 11:36:11 2012 maxime ginters
** Last update Tue Oct 09 11:36:37 2012 maxime ginters
*/

void	my_swap_char(char *a, char *b)
{
  char	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
