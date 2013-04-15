##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sun Mar 31 20:23:41 2013 maxime ginters
## Last update Sun Mar 31 20:37:12 2013 maxime ginters
##

CC	= gcc

RM	= rm -f

NASM	= nasm -f elf64

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I. -fPIC

LDFLAGS	= -shared

NAME	= libasm.so

SRCS	= strlen.S \
		  strchr.S \
		  memset.S \
		  memcpy.S \
		  strcmp.S \
		  strncmp.S \
		  strcasecmp.S \
		  rindex.S \
		  strstr.S \
		  strpbrk.S \
		  strcspn.S

OBJS	= strlen.o \
		  strchr.o \
		  memset.o \
		  memcpy.o \
		  strcmp.o \
		  strncmp.o \
		  strcasecmp.o \
		  rindex.o \
		  strstr.o \
		  strpbrk.o \
		  strcspn.o

all: $(NAME)

$(NAME):
	$(NASM) strlen.S -o strlen.o
	$(NASM) strchr.S -o strchr.o
	$(NASM) memset.S -o memset.o
	$(NASM) memcpy.S -o memcpy.o
	$(NASM) strcmp.S -o strcmp.o
	$(NASM) strncmp.S -o strncmp.o
	$(NASM) strcasecmp.S -o strcasecmp.o
	$(NASM) rindex.S -o rindex.o
	$(NASM) strstr.S -o strstr.o
	$(NASM) strpbrk.S -o strpbrk.o
	$(NASM) strcspn.S -o strcspn.o
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

