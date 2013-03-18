##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sat Dec 01 00:09:42 2012 maxime ginters
## Last update Sat Dec 01 01:13:04 2012 maxime ginters
##

CC	= cc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -ggdb3

LDFLAGS	= -ggdb3

NAME	= tko2-2

SRCS	=	commandes_parser.c \
		create_platine.c \
		functions.c \
		main.c

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

