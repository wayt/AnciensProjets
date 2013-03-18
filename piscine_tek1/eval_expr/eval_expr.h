/*
** eval_expr.h for eval_expr in /home/fest/Epitech/eval_expr
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 16:53:41 2012 maxime ginters
** Last update Fri Oct 26 18:10:13 2012 maxime ginters
*/

#ifndef EVAL_EXPR_H_
# define EVAL_EXPR_H_

int	eval_expr(char *str);
char	*trim_space(char *str);
char	*do_most_prior(char *str);
char	*get_parenthese_expr(char *str, int *st, int *e);
char	*get_sub_str(char *str, int start, int end);
char	*trim_parentheses(char *str);
char	*calc(char *str);
char	*calc_int_to_str(int a, int b, char o);
char	*str_replace(char *s, int st, int e, char *by);
int	get_operator_pos(char *str, int pos, int pre_op);
int	is_operator(char c, int important);
char	*int_to_str(int v);
char	*do_op_add(int a, int b);
char	*do_op_min(int a, int b);
char	*do_op_mult(int a, int b);
char	*do_op_div(int a, int b);
char	*do_op_mod(int a, int b);
int	get_size_for_char(int v);

#endif /* !EVAL_EXPR_H_ */
