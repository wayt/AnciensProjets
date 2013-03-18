/*
** fx.c for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_4
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Sat Dec  1 19:35:09 2012 alexandre sivadon
** Last update Sat Dec  1 23:05:27 2012 alexandre sivadon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fx.h"

int	consonne(char c)
{
  int	consonne;

  consonne = 0;
  if ((c >= 'b' && c <= 'd') || (c >= 'f' && c <= 'h')
      || (c >= 'j' && c <= 'n') || (c >= 'p' && c <= 't')
      || (c >= 'v' && c <= 'x') || (c == 'z'))
    consonne = 1;
  return (consonne);
}

int	voyelle(char c)
{
  int	voyelle;

  voyelle = 0;
  if (c == 'a' || c == 'e' || c == 'i'
      || c == 'o' || c == 'u' || c == 'y')
    voyelle = 1;
  return (voyelle);
}

char	*filter_highpass(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (voyelle(str[i]) == 1)
	str[i] -= 32;
      i++;
    }
  return (str);
}

char	*filter_lowpass(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (consonne(str[i]) == 1)
	str[i] -= 32;
      i++;
    }
  return (str);
}

char	*fx_double(char *str)
{
  int	i;
  int	j;
  char	*tmp;
  char	*res;

  i = 0;
  tmp = malloc(sizeof(char) * strlen(str));
  memset(tmp, 0, strlen(str));
  while (str[i])
    {
      tmp[i] = str[i];
      i++;
    }
  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (2 * strlen(str) + 1));
  memset(res, 0, (2 * strlen(str)+ 1));
  while (str[i])
    {
      res[j] = tmp[i];
      res[j+1] = tmp[i];
      i++;
      j+=2;
    }
  res[j] = '\0';
  return (res);
}

char	*flanger(char *str)
{
  int	i;
  int	j;
  int	count;
  char	*tmp;
  char	*res;

  i = 0;
  count = 0;
  tmp = malloc(sizeof(char) * strlen(str));
  memset(tmp, 0, strlen(str));
  while (str[i])
    {
      tmp[i] = str[i];
      if (i % 2 == 0)
	count++;
      i++;
    }
  i = 0;
  res = malloc(sizeof(char) * (strlen(str) + (4 * count) + 1));
  memset(res, 0, (strlen(str) + (4 * count) + 1));
  count = 0;
  j = 0;
  while (str[i])
    {
      if ((i % 2) == 0)
	{
	  res[j++] = 'W';
	  res[j++] = 'o';
	  res[j++] = 'O';
	  res[j++] = 'o';
	}
      else
	{
	  res[j++] = tmp[count++];
	  res[j] = tmp[count++];
	  j++;
	}
      i++;
    }
  res[j] = '\0';
  return (res);
}

char	*fx_echo(char *str)
{
  int	i;
  int	j;
  int	c;
  int	count;
  int	save_count;
  char	*res;

  i = 0;
  j = strlen(str);
  count = 0;
  while (str[i])
    {
      if (i % 2 == 0)
	count++;
      i++;
    }
  i = 0;
  res = malloc(sizeof(char) * (strlen(str) + count + 4));
  memset(res, 0, (strlen(str) + count + 4));
  c = 0;
  save_count = count;
  while (i < (int)(strlen(str) + save_count + 3))
    {
      if (i < j)
	res[c++] = str[i];
      else if (i < (j + 3))
	res[c++] = '.';
      else
	res[c++] = str[count++];
      i++;
    }
  res[c] = '\0';
  return (res);
}
