/*
** my_evil_str.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 09:11:22 2012 maxime ginters
** Last update Thu Oct 04 09:29:46 2012 maxime ginters
*/

int	my_swap_char(char *a, char *b)
{
  char temp;

  temp = *a;
  *a = *b;
  *b = temp;

  return 0;
}

char	*my_evil_str(char *str)
{
  int	start;
  int	end;

  start = 0;
  end = my_strlen(str) - 1;

  while (start < end)
    my_swap_char(str + start++, str + end--);

  return str;
}
