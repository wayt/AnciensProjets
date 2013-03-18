##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Oct 22 21:15:32 2012 maxime ginters
## Last update Tue Oct 23 18:16:26 2012 maxime ginters
##

CC	= cc
RM	= rm -f

NAME	= do-op

CFLAGS	+= -I/afs/epitech.net/users/all/ginter_m/rendu/include
CFLAGS	+= -L/afs/epitech.net/users/all/ginter_m/rendu/lib
CFLAGS	+= -lmy

SRCS	= do_op.c \
		main.c

OBJS	=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
