/*
** my_aff_alpha.c for  in /home/ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.net>
** 
** Started on  Wed Oct 03 09:38:19 2012 maxime ginters
** Last update Wed Oct 03 21:10:04 2012 maxime ginters
*/

int	my_aff_alpha()
{
  char	curr_char;

  curr_char = 'a';
  while (curr_char <= 'z')
    my_putchar(curr_char++);

  return 0;
}

