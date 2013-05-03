##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sun Apr 21 14:45:13 2013 maxime ginters
## Last update Sun Apr 28 21:49:06 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -I../src_shared
#CFLAGS	+= -ggdb3

LDFLAGS	=

NAME	= serveur

SRCS	= main.c server.c ../src_shared/list.c ../src_shared/list2.c ../src_shared/list3.c \
	  client.c client2.c ../src_shared/buffer.c commands.c commands2.c \
	  channels.c channels2.c server2.c commands3.c

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

