/*
** functions.h for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 00:36:17 2012 maxime ginters
** Last update Sat Dec  1 22:10:53 2012 alexandre sivadon
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_
#include "create_platine.h"
#include "commandes_parser.h"

struct s_functions
{
  char	c;
  void	(*funct)(t_platine*, t_platine*, t_command*);
};

typedef struct s_functions t_functions;

extern t_functions	funct_tab[];

void	handle_play(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_pause(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_rewind(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_forward(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_cue(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_reverse(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_cut(t_platine* pa, t_platine* pb, t_command* cmd);
void	handle_fx(t_platine* pa, t_platine* pb, t_command* cmd);

void	reset_all_fx(t_platine *p);

#endif /* !FUNCTIONS_H_*/
