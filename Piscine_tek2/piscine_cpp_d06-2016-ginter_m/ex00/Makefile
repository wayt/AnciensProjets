##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Jan 14 09:43:58 2013 maxime ginters
## Last update Mon Jan 14 10:00:07 2013 maxime ginters
##

CC	= g++

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror

LDFLAGS	=

NAME	= my_cat

SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

