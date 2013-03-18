##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Fri Nov 30 20:18:38 2012 maxime ginters
## Last update Fri Nov 30 21:03:57 2012 maxime ginters
##

CC	= cc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -ggdb3

LDFLAGS	= -ggdb3

NAME	= tko2-1

SRCS	=	tko2-1.c	\
		create_tab.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) *~ *# $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

