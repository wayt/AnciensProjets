/*
** my_getnbr.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 09:33:53 2012 maxime ginters
** Last update Tue Oct 09 10:22:55 2012 maxime ginters
*/

#define MAX_INT 0x7FFFFFFF

int	is_valid(char *c, int offset, int with_minus)
{
  int	size;

  size = my_strlen(c);
  if (*(c + offset) == '\0')
    return 0;
  if (*(c + offset) >= '0' && *(c + offset) <= '9')
    return 1;
  if (with_minus == 1 && *(c + offset) == '-')
    if (++offset < size - 1 && *(c + offset) >= '0' && *(c + offset) <= '9')
      return 1;
  return 0;
}

int	my_getnbr(char *str)
{
  int	offset;
  int	value;
  char	is_neg;

  offset = 0;
  value = 0;
  is_neg = 0;
  while (*(str + offset) != '\0' && is_valid(str, offset, 1) == 0)
    ++offset;
  if (*(str + offset) == '-')
  {
    is_neg = 1;
    ++offset;
  }
  while (is_valid(str, offset, 0) == 1)
  {
    if (value > MAX_INT / 10)
      return 0;
    value *= 10;
    value += *(str + offset) - '0';
    ++offset;
  }
  return (is_neg == 1 ? value * -1 : value);
}
