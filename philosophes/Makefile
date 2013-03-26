##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Mar 18 15:34:09 2013 maxime ginters
## Last update Sun Mar 24 15:13:23 2013 fabien casters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -D_REENTRANT

LDFLAGS	= -lpthread

NAME	= philo

SRCS	= main.c \
	  philosophes.c \
	  behaviors.c

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

