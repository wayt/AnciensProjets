##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Thu Oct 25 16:46:09 2012 maxime ginters
## Last update Fri Oct 26 17:58:23 2012 maxime ginters
##

CC	= cc
RM	= rm -f

CFLAGS	= -I/afs/epitech.net/users/all/ginter_m/rendu/include
CFLAGS	+= -I.
CFLAGS	+= -ggdb3

LDFLAGS	+= -L/afs/epitech.net/users/all/ginter_m/rendu/lib
LDFLAGS	+= -lmy
LDFLAGS	+= -ggdb3

NAME	= eval_expr

SRCS	= main.c \
		eval_expr.c \
		do_op.c \
		str_functions.c \
		get_functions.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
