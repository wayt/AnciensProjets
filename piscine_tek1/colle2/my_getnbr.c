/*
** my_getnbr.c for my_getnbr in /home/jean-b_x//piscine/jour_04
** 
** Made by xavier jean-bart
** Login   <jean-b_x@epitech.net>
** 
** Started on  Fri Oct  5 22:19:49 2012 xavier jean-bart
** Last update Sat Oct 13 15:36:53 2012 maxime ginters
*/

int		my_getnbr(char *str)
{
  unsigned int	nb;
  int		sign;
  int		i;

  nb = 0;
  sign = 1;
  i = 0;
  while (str[i] != 0 && (str[i] == '-'|| str[i] == '+'))
    {
      if (str[i] == '-')
        sign *= -1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (nb * 10 > 2147483647 / 10)
        return (0);
      else
        nb = nb * 10 + (str[i] - '0');
      i++;
    }
  return (nb * sign);
}
