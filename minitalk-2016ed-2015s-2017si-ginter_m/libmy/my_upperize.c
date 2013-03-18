/*
** my_upperize.c for temp_lib in /home/ginter_m/temp_lib
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 11:47:16 2012 maxime ginters
** Last update Tue Oct 09 11:48:15 2012 maxime ginters
*/

void	my_upperize(char *c)
{
  if (*c >= 'a' && *c <= 'z')
    *c += 'A' - 'a';
}
