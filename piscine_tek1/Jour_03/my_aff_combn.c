/*
** my_aff_combn.c for work in /home/ginter_m/Jour_03/work
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 17:13:15 2012 maxime ginters
** Last update Wed Oct 03 21:03:48 2012 maxime ginters
*/

int	get_max_nbr(int n)
{
  int	value;
  int	i;

  value = 9;
  i = 1;

  if (n == 0)
    return 0;

  while (i++ < n)
    value = (value * 10) + 9;

  return value;
}

int	is_valid(int val, int nb_char)
{
  int	offset;
  char	curr_off;
  char	prev_off;

  offset = 1;
  curr_off = -128;
  prev_off = -128;
  if (val < power(10, nb_char - 2))
    return 0;
  while (offset < val)
  {
    curr_off = (val / offset) % 10;
    if (curr_off == 0 && prev_off == -128)
      return 0;
    if (prev_off == -128)
      prev_off = curr_off;
    else
    {
      if (prev_off <= curr_off)
        return 0;
      prev_off = curr_off;
    }
    offset *= 10;
  }
  return 1;
}

void	print_value(int val, int nb_char)
{
  int	offset;
  char	curr_off;

  offset = power(10, nb_char - 1);
  curr_off = 0;

  while (offset > 0)
  {
    curr_off = (val / offset) % 10;
    my_putchar('0' + curr_off);

    offset /= 10;
  }
}

int	power(int nb, int power)
{
  int	i;
  int	result;

  i = 0;
  result = 1;

  while (i++ < power)
    result *= nb;

  return result;
}

int	my_aff_combn(int n)
{
  int	value;
  int	max_value;
  char	first;

  value = -1;
  max_value = get_max_nbr(n);
  first = 1;

  while (++value <  max_value)
  {
    if (is_valid(value, n) == 1)
    {
      if (first == 1)
        first = 0;
      else
      {
        my_putchar(',');
        my_putchar(' ');
      }
      print_value(value, n);
    }
  }
}
