/*
** my_aff_revalpha.c for  in /home/ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.net>
** 
** Started on  Wed Oct 03 09:38:19 2012 maxime ginters
** Last update Wed Oct 03 21:19:29 2012 maxime ginters
*/

int	my_aff_revalpha()
{
  char	curr_char;

  curr_char = 'z';
  while (curr_char >= 'a')
    my_putchar(curr_char--);

  return 0;
}

