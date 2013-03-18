##
## Makefile for colle in /home/nguy_v//afs/rendu/piscine/colles/Semaine_01
## 
## Made by virgil nguyen
## Login   <nguy_v@epitech.net>
## 
## Started on  Sat Oct  6 13:54:45 2012 virgil nguyen
## Last update Sat Oct  6 14:01:18 2012 virgil nguyen
##

CC= gcc

NAME1= colle1-1

NAME2= colle1-2

NAME3= colle1-3

NAME4= colle1-4

NAME5= colle1-5

SRC= my_putchar.c my_getnbr.c

SRC1= colle1-1.c

SRC2= colle1-2.c

SRC3= colle1-3.c

SRC4= colle1-4.c

SRC5= colle1-5.c

all: CCcolle1 CCcolle2 CCcolle3 CCcolle4 CCcolle5

CCcolle1:
	$(CC) -o $(NAME1) $(SRC) $(SRC1)

CCcolle2:
	$(CC) -o $(NAME2) $(SRC) $(SRC2)

CCcolle3:
	$(CC) -o $(NAME3) $(SRC) $(SRC3)

CCcolle4:
	$(CC) -o $(NAME4) $(SRC) $(SRC4)

CCcolle5:
	$(CC) -o $(NAME5) $(SRC) $(SRC5)

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

re: flcean all