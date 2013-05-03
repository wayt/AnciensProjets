##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Thu Apr 25 14:55:49 2013 maxime ginters
## Last update Sat Apr 27 13:34:50 2013 fabien casters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -I../../src_shared

LDFLAGS	= -lcurses

NAME	= interface

SRCS	= main.c \
	  interface.c \
	  ichans.c \
	  iusers.c \
	  imesgs.c \
	  iinput.c \
	  ../../src_shared/list.c

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

