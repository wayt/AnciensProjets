/*
** bistromathique.h for bistromathique in /home/fest/Epitech/bistromathique
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Nov 02 11:09:25 2012 maxime ginters
** Last update Wed Nov 07 14:46:54 2012 maxime ginters
*/

#include <stdlib.h>

#ifndef BISTROMATHIQUE_H_
# define BISTROMATHIQUE_H_

#define OP_OPEN_PARENT_IDX	0
#define OP_CLOSE_PARENT_IDX	1
#define OP_PLUS_IDX		2
#define OP_SUB_IDX		3
#define OP_NEG_IDX		3
#define OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define OP_MOD_IDX		6

#define SYNTAXE_ERROR_MSG	"syntax error\n"
#define ABS(a) (((a) < 0) ? -(a) : (a))

struct s_base
{
  int	length;
  char	*str;
  char	value[255];
};

typedef struct s_base t_base;

/*
** eval_expr.c
*/
char	*eval_expr(char *base, char *ops, char *expr, int size);
char	*do_most_prior(char *expr, t_base *base, char ops[7]);
char	*calc(char *expr, t_base *base, char ops[7]);
char	*calc_str(char *tab[2], t_base *base, char c, char ops[7]);

/*
** bistromathique.c
*/
t_base	*formate_base(char *str);
void	free_base(t_base *b);
void	formate_operator(char *str, char ops[7]);

/*
** str_utils.c
*/
int	expr_is_full_num(char *expr, t_base *base, char ops[7]);
char	*get_parentheses_expr(char *expr, int *st, int *e, char ops[7]);
char	*get_sub_str(char *str, int start, int end);
char	*trim_parentheses(char *str, char ops[7]);
char	*str_replace(char *s, int st, int e, char *by);

/*
** calc_utils.c
*/
int	get_operator_pos(char *expr, char ops[7], int pos, int pre_op);
int	is_operator(char c, char ops[7], int impo);

/*
** misc.c
*/
void	check_malloc(void *ptr);

#endif /* !BISTROMATHIQUE_H_ */
