##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Thu Mar 14 15:45:59 2013 maxime ginters
## Last update Fri Mar 22 16:14:22 2013 maxime ginters
##

CC	= g++

RM	= rm -f

CP	= cp -f

CXXFLAGS	+= -Wextra -Wall -Werror
CXXFLAGS	+= -I. -I.. -fPIC

LDFLAGS	= -lcurses

NAME	= lib_nibbler_ncurses.so

SRCS	= GraphicNCurses.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared $(OBJS) -o $(NAME) $(LDFLAGS)
	$(CP) $(NAME) ../../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

