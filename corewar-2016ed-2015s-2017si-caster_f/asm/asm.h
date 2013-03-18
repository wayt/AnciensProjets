/*
** asm.h for corewar in /home/leroy_v/Epitech/corewar/asm
**
** Made by fabien casters
** Login <fabien.casters@epitech.eu>
**
** Started on Mon Dec 03 13:12:15 2012 fabien casters
** Last update Sat Dec 15 17:17:16 2012 fabien casters
*/

#ifndef ASM_H_
# define ASM_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include "my.h"
#include "get_next_line.h"
#include "stdlist.h"

/*
** Error message
*/

#define SYNTAX_ERROR	"Syntax error line %d\n"
#define INDIR_ERROR	"Warning Indirection to far line %d\n"
#define LABEL_ERROR	"Label %s undefine line %d\n"
#define REG_ERROR	"No such register line %d\n"
#define DIR_ERROR	"Warning Direct too big line %d\n"
#define FILE_ERROR	"File %s not accessible\n"
#define NAME_ERROR	"Warning multiple name line %d\n"
#define COMMENT_ERROR	"Warning multiple comment line %d\n"
#define STRING_ERROR	"Unterminated string line %d\n"
#define MALLOC_ERROR	"Can't perform malloc\n"
#define INPUT_ERROR	"./asm file_name[.s]\n"
#define ARG_INF_ERROR	"Too few arguments line %d\n"
#define ARG_SUP_ERROR	"Too many arguments line %d\n"
#define ARG_ERROR	"Illegal argument line %d\n"
#define MNE_ERROR	"Unknown mnemonique line %d\n"
#define TYPE_ERROR	"Unknown type of data line %d\n"

typedef struct s_cmd
{
  char		*str;
  char		*cmd;
  char		*mne;
  char		**arg;
  char		*label;
  int		line;
  char		cmd_hex[20];
  int		byte;
  op_t		*op;
}		t_cmd;

int		count_space(char *str);
char		*get_name_file(char *name);
char		*verif_name_file(char *name);
void		compile(int fd, char *name);
int		is_name_comment(char *line);
int		recup_name_comm(char *line, int l, header_t *head);
void		add_cmd(char *s, int line, header_t *head, t_list *prog);
void		free_cmd(t_cmd *cmd);
void		list_to_hexa(t_list *prog, int fd);
unsigned int	my_getunbr(char *str);

/*
** Error function
*/

void	error(char *msg, int quit);
void	line_error(char *msg, int line, int quit);
void	string_error(char *msg, char *str, int quit);
void	string_line_error(char *msg, char *str, int line, int quit);

/*
** Process function
*/
char	get_cbyte(char **, int);
void	create_cmd_hex(t_list *);
unsigned int	get_type_value(char *);
int	get_type(char *);
void	create_cmd_hex(t_list *);
void	create_label_hex(t_list *);
void	add_cmd_hex(t_cmd *, unsigned int, int, int);
op_t	*get_op(char *);

#endif
