##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Tue Dec 04 01:38:29 2012 maxime ginters
## Last update Sun Dec 16 19:24:31 2012 vincent leroy
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.
CFLAGS	+= -I./param_parser
CFLAGS	+= -I./virtual_machine
CFLAGS	+= -I./commands
CFLAGS	+= -I../lib
CFLAGS	+= -I../lib/list

LDFLAGS	= -L../lib -lmy
LDFLAGS	+= -L../lib/list -llist

MAKE	= make -C

LIBDIR	= ../lib

NAME	= corewar

SRCS	=	main.c \
		op.c \
		corewar.c \
		param_parser/param_parser.c \
		param_parser/param_setter.c \
		param_parser/param_cleaner.c \
		virtual_machine/vm_launcher.c \
		virtual_machine/vm_run.c \
		virtual_machine/endian_tools.c \
		virtual_machine/vm_tools.c \
		virtual_machine/dump_memory.c \
		commands/commands.c \
		commands/messages.c \
		commands/cmd_live.c \
		commands/cmd_ld.c \
		commands/cmd_st.c \
		commands/cmd_add.c \
		commands/cmd_sub.c \
		commands/cmd_and.c \
		commands/cmd_or.c \
		commands/cmd_xor.c \
		commands/cmd_zjmp.c \
		commands/cmd_ldi.c \
		commands/cmd_sti.c \
		commands/cmd_fork.c \
		commands/cmd_lld.c \
		commands/cmd_lldi.c \
		commands/cmd_lfork.c \
		commands/cmd_mul.c \
		commands/cmd_div.c \
		commands/cmd_mod.c \
		commands/cmd_aff.c

OBJS	= $(SRCS:.c=.o)

all: libmy $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

libmy:
	$(MAKE) $(LIBDIR)

addebug:
	$(CFLAGS) += -ggdb3

debug: addebug all

.PHONY: all clean fclean re debug libmy
