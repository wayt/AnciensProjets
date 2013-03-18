/*
** my_memset.c for my_memset in /home/leroy_v//Bistromathique
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Thu Nov  1 11:14:54 2012 vincent leroy
** Last update Thu Nov  1 11:15:03 2012 vincent leroy
*/

void    my_memset(void *buf, char c, int size)
{
  char  *pt;

  pt = (char*)buf;
  size--;
  while (size >= 0)
    pt[size--] = c;
}
