##
## Makefile for  in /home/vaga/Projects/tek2/malloc/tp
## 
## Made by fabien casters
## Login   <fabien.casters@epitech.eu>
## 
## Started on  Tue Feb 05 10:40:45 2013 fabien casters
## Last update Sat Feb 09 16:53:12 2013 fabien casters
##

NAME    = libmalloc.so

CFLAGS  = -fPIC -Werror -Wextra -Wall -W -I.
LDFLAGS = -shared -lpthread -ggdb3

SRC     = malloc.c \
	  free.c

OBJ     = $(SRC:.c=.o)

CC      = gcc

RM      = rm -f

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean

