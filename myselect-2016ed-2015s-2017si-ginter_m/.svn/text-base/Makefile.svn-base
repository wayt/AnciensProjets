##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Nov 19 11:06:39 2012 maxime ginters
## Last update Fri Nov 23 19:19:10 2012 maxime ginters
##

CC	= cc

RM	= rm -f

#CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -I./include
CFLAGS	+= -I./list
CFLAGS	+= -I./key_functions

LDFLAGS	= -L./lib
LDFLAGS	+= -lmy
LDFLAGS	+= -lncurses
LDFLAGS	+= -ggdb3

NAME	= my_select

SRCS	= my_select.c \
		utils.c \
		window_utils.c \
		list/create_list.c \
		list/free_list.c \
		list/find_list.c \
		list/list_utils.c \
		key_functions/handle_up.c \
		key_functions/handle_down.c \
		key_functions/handle_left.c \
		key_functions/handle_right.c \
		key_functions/handle_space.c \
		key_functions/handle_enter.c \
		key_functions/handle_delete.c \
		key_functions/handle_null.c

OBJS	= $(SRCS:.c=.o)

MAKE	= make -C

LIBDIR	= ./libmy

all: libmy $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(MAKE) $(LIBDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libmy:
	$(MAKE) $(LIBDIR)

.PHONY: all clean fclean re libmy

