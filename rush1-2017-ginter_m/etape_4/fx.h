/*
** fx.h for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_4
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Sat Dec  1 21:07:14 2012 alexandre sivadon
** Last update Sat Dec  1 21:09:58 2012 alexandre sivadon
*/

#ifndef FX_H_
#define FX_H_

int	consonne(char c);
int	voyelle(char c);
char	*filter_highpass(char *str);
char	*filter_lowpass(char *str);
char	*fx_double(char *str);
char	*flanger(char *str);
char	*fx_echo(char *str);

#endif /* FH_H_ */
