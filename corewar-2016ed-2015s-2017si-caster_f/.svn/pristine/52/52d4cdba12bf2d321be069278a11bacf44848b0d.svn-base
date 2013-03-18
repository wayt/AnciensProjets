##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Mon Dec 03 14:39:22 2012 vincent leroy
## Last update Tue Dec 11 17:10:02 2012 vincent leroy
##

SRC	= my_getnbr.c \
	  my_malloc.c \
	  my_memset.c \
	  my_printf.c \
	  my_putnbr.c \
	  my_putstr.c \
	  my_str_to_wordtab.c \
	  my_strcmp.c \
	  my_strlen.c \
	  my_strncpy.c \
	  my_strcat.c \
	  my_strcpy.c \
	  get_next_line.c \
	  my_strdup.c \
	  my_strncmp.c \
	  free_tab.c \
	  is_bigendian.c \
	  my_memcpy.c

CC	= gcc

RM	= rm -f

FLAG	= -Wall -I.

CFLAGS	= $(FLAG)

LDFLAGS	= $(FLAG)

NAME	= libmy.a

MAKE	= make -C
LIBLIST	=./list

OBJ	= $(SRC:.c=.o)

all: liblist $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(MAKE) $(LIBLIST) clean
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

liblist:
	$(MAKE) $(LIBLIST)

.PHONY: all clean fclean re liblist
