##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Feb 11 16:33:38 2013 maxime ginters
## Last update Thu Feb 28 14:56:00 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -Iparams -Icore

LDFLAGS	=

NAME	= my_script

SRCS	= main.c \
	  params/param_functions.c \
	  params/params_parser.c \
	  core/core.c \
	  core/init.c \
	  my_libc.c \
	  my_libc2.c

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

