##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Fri Feb 15 15:11:52 2013 maxime ginters
## Last update Sun Feb 24 14:28:14 2013 fabien casters
##

CC	= g++

RM	= rm -f

CXXFLAGS	+= -Wextra -Wall -Werror -Weffc++
CXXFLAGS	+= -I. -IOperand -IException -IConfig

LDFLAGS	=

NAME	= avm

SRCS	= main.cpp \
	  Operand/AOperand.cpp \
	  Operand/Int8.cpp \
	  Operand/Int16.cpp \
	  Operand/Int32.cpp \
	  Operand/Float.cpp \
	  Operand/Double.cpp \
	  Operand/OperandFactory.cpp \
	  Config/Config.cpp \
	  VMParser.cpp \
	  VMCore.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

