/*
** my_aff_comb.c for Jour_03 in /home/ginter_m/Jour_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 14:22:30 2012 maxime ginters
** Last update Wed Oct 03 21:11:34 2012 maxime ginters
*/

int	print_value(char a, char b, char c)
{
  my_putchar(a);
  my_putchar(b);
  my_putchar(c);

  if (!(a == '7' && b == '8' && c == '9'))
  {
    my_putchar(',');
    my_putchar(' ');
  }
}

int	my_aff_comb()
{
  char	undred;
  char	decade;
  char	unit;

  undred = '0';
  decade = '0';
  unit = '0';
  while (undred <= '7')
  {
    while (decade <= '8')
    {
      while (unit <= '9' && undred < decade)
      {
        if (decade < unit)
          print_value(undred, decade, unit);
        ++unit;
      }
      unit = '0';
      ++decade;
    }
    decade = '0';
    ++undred;
  }
}
