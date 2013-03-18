/*
** my_getnbr.c for my_getnbr in /home/leroy_v//piscine/Jour_04/exo04
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Sun Oct 14 20:36:44 2012 vincent leroy
** Last update Thu Oct 18 17:39:50 2012 vincent leroy
*/

int	my_sign(char *str, int *sign)
{
  int	i;

  *sign = 1;
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      *sign = (str[i] == '+' ? 1 : -1);
      i++;
    }
  return (i);
}

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	nb;

  i = my_sign(str, &sign);
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (nb * sign);
      else if (nb >= 214748364 && str[i] > '8' && sign == -1)
	return (0);
      else if (nb == 214748364 && str[i] == '8' && sign == -1)
	return (-2147483648);
      else if (nb >= 214748364 && str[i] > '7' && sign == 1)
	return (0);
      nb *= 10;
      nb += str[i] - '0';
      i++;
    }
  return (nb * sign);
}
