/*
** my_aff_comb2.c for work in /home/ginter_m/Jour_03/work
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 15:17:04 2012 maxime ginters
** Last update Wed Oct 03 21:18:34 2012 maxime ginters
*/

int	print_value(char a, char b, char c, char d)
{
  if (!(a < c || (a == c && b < d)))
    return;

  my_putchar(a);
  my_putchar(b);
  my_putchar(' ');
  my_putchar(c);
  my_putchar(d);

  if (!(a == '9' && b == '8' && c == '9' && d == '9'))
  {
    my_putchar(',');
    my_putchar(' ');
  }
}

int	my_aff_comb2()
{
  char	m;
  char	c;
  char	d;
  char	u;

  m = '0';
  c = '0';
  d = '0';
  u = '0';
  while (m <= '9' && c <= '9' && d <= '9' && u <= '9')
  {
    print_value(m, c, d, u);
    if (++u > '9')
    {
      u = '0';
      if (++d > '9')
      {
        d = '0';
        c = (++c > '9' ? '0' : c);
        if (c == '0')
          ++m;
      }
    }
  }
}

int	main()
{
  my_aff_comb2();
}
