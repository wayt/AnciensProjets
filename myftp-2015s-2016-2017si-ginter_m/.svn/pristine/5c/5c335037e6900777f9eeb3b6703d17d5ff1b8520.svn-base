##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Wed Apr 10 14:42:48 2013 maxime ginters
## Last update Sun Apr 14 19:52:54 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I.

LDFLAGS	=

NAME	= serveur

SRCS	= main.c serveur.c commands.c commands2.c handler.c handler2.c handler3.c

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

