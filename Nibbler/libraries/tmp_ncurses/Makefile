##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Thu Mar 14 15:45:59 2013 maxime ginters
## Last update Fri Mar 22 14:49:49 2013 maxime ginters
##

CC	= g++

RM	= rm -f

CXXFLAGS	+= -Wextra -Wall
CXXFLAGS	+= -I. -I.. -ggdb3

LDFLAGS	= -lcurses

NAME	= Nibbler

SRCS	= main.cpp GraphicNCurses.cpp

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

