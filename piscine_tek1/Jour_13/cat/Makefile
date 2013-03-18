##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Wed Oct 24 13:46:39 2012 maxime ginters
## Last update Thu Oct 25 18:41:42 2012 maxime ginters
##

CC	= cc
RM	=rm -f

CFLAGS	= -I/u/all/ginter_m/rendu/include 

LDFLAGS	+= -L//u/all/ginter_m/rendu/lib
LDFLAGS	+= -lmy

NAME	= cat

SRCS	= main.c \
		my_super_putstr.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
