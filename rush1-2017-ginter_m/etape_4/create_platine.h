/*
** create_plateforme.h for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_2
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Fri Nov 30 23:36:40 2012 alexandre sivadon
** Last update Sat Dec 01 21:16:06 2012 maxime ginters
*/

#ifndef FCT_H_
#define FCT_H_

typedef struct s_platine
{
  char	**cmd;
  int	index;
  char	active;
  char	reversed;
  char	lowpass;
  char	highpass;
  char	doubl;
  char	flanger;
  char	echo;
}t_platine;

t_platine	*create_platine(char *file);

#endif
