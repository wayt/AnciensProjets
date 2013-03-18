/*
** my_getnbr.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 09:33:53 2012 maxime ginters
** Last update Tue Oct 23 14:03:10 2012 maxime ginters
*/

#ifndef MAX_INT
  #define MAX_INT 0x7FFFFFFF
#endif
#ifndef MIN_INT
  #define MIN_INT 0x80000000
#endif

int	my_strlen(char *);

int	is_getnbr_valid(char *c, int offset)
{
  int	size;

  size = my_strlen(c);
  if (*(c + offset) == '\0')
    return 0;
  if (*(c + offset) >= '0' && *(c + offset) <= '9')
    return 1;
  return 0;
}

int	my_getnbr(char *str)
{
  int	offset;
  int	value;
  char	signe;

  offset = 0;
  value = 0;
  signe = 1;
  while (*(str + offset) != '\0' && is_getnbr_valid(str, offset) == 0)
  {
    signe *= (*(str + offset) == '-' ? -1 : 1);
    if (*(str + offset) != '-' && *(str + offset) != '+')
      return (0);
    ++offset;
  }
  while (is_getnbr_valid(str, offset) == 1)
  {
    if (value > (signe == -1 ? MIN_INT : MAX_INT) / 10)
      return 0;
    value *= 10;
    value += *(str + offset) - '0';
    ++offset;
  }
  return (value * signe);
}
