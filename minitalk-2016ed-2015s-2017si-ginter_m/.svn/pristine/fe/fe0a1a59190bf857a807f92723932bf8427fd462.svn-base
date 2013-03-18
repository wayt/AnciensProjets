##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Nov 12 12:02:44 2012 maxime ginters
## Last update Sat Nov 17 19:10:57 2012 maxime ginters
##

CC	= gcc

RM	= rm -f

MAKE	= make -C

LIBDIR	= ./libmy

#CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+= -ansi
CFLAGS	+= -pedantic
CFLAGS	+= -I./include
CFLAGS	+= -I./Server
CFLAGS	+= -ggdb3

LDFLAGS	= -L./lib
LDFLAGS	+= -lmy
LDFLAGS	+= -ggdb3

SNAME	= server
CNAME	= client

SSRCS	= Server/server.c \
		Server/client.c
CSRCS	= Client/client.c

SOBJS	= $(SSRCS:.c=.o)
COBJS	= $(CSRCS:.c=.o)

all: libmy $(SNAME) $(CNAME)

$(SNAME): $(SOBJS)
	$(CC) $(SOBJS) -o $(SNAME) $(LDFLAGS)

$(CNAME): $(COBJS)
	$(CC) $(COBJS) -o $(CNAME) $(LDFLAGS)

libmy:
	$(MAKE) $(LIBDIR)

clean:
	$(RM) $(SOBJS) $(COBJS)
	$(MAKE) $(LIBDIR) clean

fclean: clean
	$(RM) $(SNAME) $(CNAME)

re: fclean all

.PHONY: all clean fclean re libmy

