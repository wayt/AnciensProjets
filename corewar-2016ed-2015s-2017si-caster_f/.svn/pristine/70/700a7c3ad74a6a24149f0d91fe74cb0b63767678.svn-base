/*
** is_bigendian.c for lib in /home/leroy_v/github/CoreWar/lib
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Dec 08 15:54:10 2012 vincent leroy
** Last update Sat Dec 08 15:54:26 2012 vincent leroy
*/

int	is_bigendian()
{
  int	nb;
  char	*c;

  nb = 0x70AB12CD;
  c = (char*)&nb;
  if (*c == 0x70)
    return (1);
  else
    return (0);
}
