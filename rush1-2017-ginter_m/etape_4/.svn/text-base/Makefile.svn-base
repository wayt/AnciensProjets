##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sat Dec 01 00:09:42 2012 maxime ginters
## Last update Sat Dec  1 23:06:11 2012 alexandre sivadon
##

CC	= cc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -ggdb3

LDFLAGS	= -ggdb3

NAME	= tko2-4

SRCS	=	commandes_parser.c \
		create_platine.c \
		functions.c \
		main.c \
		play.c \
		cue.c \
		cut.c \
		handle_fx.c \
		fx.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

