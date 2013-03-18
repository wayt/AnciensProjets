##
## Makefile for libdlist in /home/leroy_v//Epitech/linked_list/dll
## 
## Made by vincent leroy
## Login   <leroy_v@epitech.net>
## 
## Started on  Mon Oct 22 09:15:22 2012 vincent leroy
## Last update Tue Dec 11 12:49:58 2012 vincent leroy
##

SRC	= stdlist.c \
	  stdlistadd.c \
	  stdlistrm.c \
	  stdlistsort.c \
	  stdlistsearch.c

NAME	= liblist.a

HEAD	= stdlist.h

CC	= gcc

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CFLAGS	= -Wall

LDFLAGS	= -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *#

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
