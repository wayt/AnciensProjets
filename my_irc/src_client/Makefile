##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Thu Apr 25 14:55:49 2013 maxime ginters
## Last update Sun Apr 28 21:25:49 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -I../src_shared -Incurses
#CFLAGS	+= -ggdb3

LDFLAGS	= -lcurses

NAME	= client

SRCS	= main.c ../src_shared/buffer.c ../src_shared/list.c ../src_shared/list2.c \
	  master.c server.c commands.c channels.c ../src_shared/list3.c \
	  handler.c ncurses/ichans.c ncurses/iinput.c ncurses/imesgs.c \
	  ncurses/interface.c ncurses/iusers.c ncurses/keys.c master2.c \
	  channels2.c channels3.c commands2.c commands3.c handler2.c handler3.c \
	  file.c

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

