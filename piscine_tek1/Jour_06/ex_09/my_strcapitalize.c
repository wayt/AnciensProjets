/*
** my_strcapitalize.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 11:42:11 2012 maxime ginters
** Last update Mon Oct 08 11:57:37 2012 maxime ginters
*/

void	my_lowerize(char *c)
{
  if (*c >= 'A' && *c <= 'Z')
    *c += 'a' - 'A';
}

void 	my_upperize(char *c)
{
  if (*c >= 'a' && *c <= 'z')
    *c += 'A' - 'a';
}

char*	my_strcapitalize(char *str)
{
  int	i;
  int	next_capitale;

  i = 0;
  next_capitale = 1;

  while (*(str + i) != '\0')
  {
    if (*(str + i) == ' ' || *(str + i) == '+' || *(str + i) == '-')
      next_capitale = 1;
    else
    {
      if (next_capitale == 1)
        my_upperize(str + i);
      else
        my_lowerize(str + i);
      next_capitale = 0;
    }
    ++i;
  }

  return (str);
}
