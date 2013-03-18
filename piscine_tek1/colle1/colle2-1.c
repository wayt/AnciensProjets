/*
** colle2-1.c for colle2_1 in /home/nguy_v//colle2-1
** 
** Made by virgil nguyen
** Login   <nguy_v@epitech.net>
** 
** Started on  Sat Oct 15 15:42:22 2011 virgil nguyen
** Last update Sat Oct 13 11:29:21 2012 virgil nguyen
*/

void	timer(int c)
{
  usleep(1000 * c);
}

void	espase(int taille)
{
 my_putchar('\r');
 while (taille >= 0)
   {
     my_putchar(' ');
     taille--;
   }
}

void	aff_1(char *str, int taille, int nb)
{
  int	i;
  int	cpt;
  int	cpt2;
  int	cache;

  cache = taille;
  i = 0;
  cpt = 0;
  espase(taille);
  while (taille > 0)
    {
      i = 0;
      cpt2 = cpt;
      while (cpt2 >= 0)
	{
	  my_putchar('\b');
	  cpt2--;
	}
      while (i <= cpt && cache >= i)
	{
	  my_putchar(str[i]);
	  i++;
	}
      cpt++;
      timer(nb);
      taille--;
    }
}

void	aff_2(char *str, int nb)
{
  int	i;

  i = 0;
  my_putchar('\r');
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
      timer(nb);
      if (str[i] == 0)
	{
	  i = 0;
	  my_putchar('\r');
	  while (str[i])
	    {
	      my_putchar(' ');
	      i++;
	    }
	}
    }
}

int	conditioncol(char *str, int collone, int rem)
{
  if (str == 0)
    collone = rem;
  else
    collone++;
  return (collone);
}
