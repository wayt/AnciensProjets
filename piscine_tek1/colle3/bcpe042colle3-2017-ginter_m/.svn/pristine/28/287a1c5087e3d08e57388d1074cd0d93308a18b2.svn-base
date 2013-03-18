/*
** my_showmem.c for ex_18 in /home/ginter_m/Jour_06/ex_18
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 17:10:18 2012 maxime ginters
** Last update Tue Oct 09 13:06:41 2012 maxime ginters
*/

int	my_strlen(char *);
int	my_putstr(char *);
int	my_is_printable(char);
void	my_putnbr_base_size(int, int);

void	show_mem_line(char *str, int offset, int size)
{
  int	i;

  my_putnbr_base_size(offset, 8);
  my_putstr(" ");
  i = 0;
  while (i < size)
  {
    my_putnbr_base_size(*(str + i + offset), 2);
    if ((i + 1) % 2 == 0)
      my_putstr(" ");
    else if (!(i + 1 < size))
      my_putstr("  ");
    ++i;
  }
    while (i < 16)
      my_putstr((i++ + 1) % 2 == 0 ? " " : "    ");

  i = 0;
  while (i < size)
  {
    if (my_is_printable(*(str + offset + i++)) == 1)
      write(1, str + offset + i - 1, 1);
    else
      write(1, ".", 1);
  }
}

int	my_showmem(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
  {
    show_mem_line(str, i, i + 16 > size ? size - i : 16);
    write(1, "\n", 1);
    i += 16;
  }
  return (0);
}
