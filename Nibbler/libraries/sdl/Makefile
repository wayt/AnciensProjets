##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Thu Mar 07 19:41:13 2013 vincent leroy
## Last update Thu Mar 21 16:17:42 2013 fabien casters
##

SRC			= GraphicSDL.cpp \
			  EventSDL.cpp \
			  StringSDL.cpp

NAME		= lib_nibbler_sdl.so

CXXFLAGS	=  -Wall -Wextra -W -Werror -Weffc++
CXXFLAGS	+= `sdl-config --cflags`
CXXFLAGS	+= -I../
CXXFLAGS	+= -fPIC

LDFLAGS		= `sdl-config --libs`
LDFLAGS		+= -lSDL_image
LDFLAGS		+= -lSDL_ttf

OBJ			= $(SRC:.cpp=.o)

RM			= rm -f

CXX			= g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared $(OBJ) $(LDFLAGS) -o $(NAME)
	cp $(NAME) ../../

clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
