##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Wed Mar 20 13:07:01 2013 vincent leroy
## Last update Wed Mar 20 22:19:35 2013 vincent leroy
##

SRC			= main.cpp \
			  Map.cpp

NAME		= nibbler

CXXFLAGS	= -Wall -Wextra -W -Werror -Weffc++
CXXFLAGS	+= -I../libraries/

LDFLAGS		= -ldl

OBJ			= $(SRC:.cpp=.o)

RM			= rm -f

CXX 		= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
