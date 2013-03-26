##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Thu Mar 07 19:41:13 2013 vincent leroy
## Last update Sat Mar 23 16:07:50 2013 fabien casters
##

SRC			= GraphicOpenGL.cpp \
			  EventSDL.cpp

NAME		= lib_nibbler_opengl.so

CXXFLAGS	=  -Wall -Wextra -W -Werror
CXXFLAGS	+= `sdl-config --cflags`
CXXFLAGS	+= -I../
CXXFLAGS	+= -fPIC

LDFLAGS		= `sdl-config --libs`
LDFLAGS		+= -lGL -lGLU -lglut

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
