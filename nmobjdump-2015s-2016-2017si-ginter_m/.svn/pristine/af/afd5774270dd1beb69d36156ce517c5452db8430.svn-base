##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Tue Mar 12 14:04:00 2013 maxime ginters
## Last update Sun Mar 17 17:17:14 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -I../Shared

LDFLAGS	=

NAME	= my_objdump

SRCS	= main.c objdump.c ../Shared/utils.c ../Shared/utils2.c

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

