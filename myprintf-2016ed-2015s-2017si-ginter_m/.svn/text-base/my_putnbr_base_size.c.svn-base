/*
** my_putnbr_base.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:13:16 2012 maxime ginters
** Last update Tue Oct 09 13:03:20 2012 maxime ginters
*/

int	my_putstr(char *);
char	*my_revstr(char *);
char	*my_strcpy(char *, char *);
void	init_putnbr_base_tab(char *);
int	my_strlen(char *);

void	my_putnbr_base_size(int nbr, int nb_char)
{
  int	base_size;
  char	value[1024];
  char	base[17];
  int	i;

  init_putnbr_base_tab(value);
  base_size = 16;
  i = 0;
  my_strcpy(base, "0123456789abcdef");
  while (nbr > 0)
  {
    value[i++] = *(base + (nbr % base_size));
    nbr /= base_size;
  }
  i = 0;
  nbr = my_strlen(value);
  if (nbr < nb_char)
    while (i++ < nb_char - nbr)
      write(1, "0", 1);
  my_putstr(my_revstr(value));
}
