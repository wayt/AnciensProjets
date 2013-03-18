/*
** my_aff_chiffre.c for  in /home/ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.net>
** 
** Started on  Wed Oct 03 09:38:19 2012 maxime ginters
** Last update Wed Oct 03 21:11:03 2012 maxime ginters
*/

int	my_aff_chiffre()
{
  char	curr_nb;

  curr_nb = '1';
  while (curr_nb <= '9')
    my_putchar(curr_nb++);

  return 0;
}

