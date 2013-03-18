/*
** my_lowerize.c for temp_lib in /home/ginter_m/temp_lib
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 11:46:14 2012 maxime ginters
** Last update Tue Oct 30 18:06:34 2012 maxime ginters
*/

void	my_lowerize(char *c)
{
  if (*c >= 'A' && *c <= 'Z')
    *c += 'a' - 'A';
}

char	to_lower(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 'a' - 'A');
  return (c);
}
