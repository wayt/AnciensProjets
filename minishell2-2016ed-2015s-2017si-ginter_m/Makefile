##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sat Nov 03 16:24:05 2012 maxime ginters
## Last update Fri Nov 30 19:15:02 2012 maxime ginters
##

CC	= cc

RM	= rm -f

MAKE	= make -C

LIBMY	= ./libmy

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -I./env
CFLAGS	+= -I./include
#CFLAGS	+= -ggdb3

LDFLAGS	= -L./lib
LDFLAGS	+= -lmy
#LDFLAGS	+= -ggdb3

NAME	= mysh

SRCS	= main.c \
		mysh.c \
		init_functions.c \
		commandes_parser.c \
		do/do_exit.c \
		do/do_env.c \
		do/do_setenv.c \
		do/do_unsetenv.c \
		do/do_cd.c \
		do/do_cd_utils.c \
		do/do_shell_bin.c \
		do/do_shell_bin_utils.c \
		env/create_functions.c \
		env/env_functions.c \
		env/find_functions.c \
		env/mod_functions.c

OBJS	= $(SRCS:.c=.o)

all: libmy $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(MAKE) $(LIBMY) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libmy:
	$(MAKE) $(LIBMY)

.PHONY: all clean fclean re libmy

