/*
** colle2_4_check_char.c for colle2_4_check_char in /home/jean-b_x//colles_piscine/colle2_4
** 
** Made by xavier jean-bart
** Login   <jean-b_x@epitech.net>
** 
** Started on  Sat Oct 13 12:08:19 2012 xavier jean-bart
** Last update Sat Oct 13 15:25:19 2012 xavier jean-bart
*/

int	is_alphanum(char c)
{
  if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'
      || c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_punctuation(char c)
{
  if (c == '.' || c == ',' || c == ';' || c == '?'
      || c == '!' || c == ':')
    return (1);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	aff_space(int i)
{
  while (i > 0)
    {
      my_putchar(' ');
      i--;
    }
}
