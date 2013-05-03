##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Apr 15 11:38:20 2013 maxime ginters
## Last update Sun Apr 21 13:10:05 2013 maxime ginters
##

CXX	= g++

RM	= rm -f

CXXFLAGS	+= -Wextra -Wall -Werror -ggdb3
CXXFLAGS	+= -I. -IPizza -IGraphic -D_REENTRANT

LDFLAGS	= -lpthread -lcurses

NAME	= plazza

SRCS	= main.cpp Accueil.cpp Kitchen.cpp Cook.cpp Runnable.cpp Mutex.cpp \
		  Pizza/Pizza.cpp Pizza/Americana.cpp Pizza/Fantasia.cpp Pizza/Margarita.cpp \
		  Pizza/Regina.cpp Log.cpp Utils.cpp ConditionalVariable.cpp Pizza/PizzaFactory.cpp \
		  CommunicatorAK.cpp CommunicatorKA.cpp Stream.cpp \
		  Graphic/GKitchen.cpp Graphic/Plazza.cpp ScopLock.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

