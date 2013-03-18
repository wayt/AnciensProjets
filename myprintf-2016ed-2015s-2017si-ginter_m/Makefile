##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Mon Oct 22 09:46:20 2012 maxime ginters
## Last update Sun Nov 18 15:16:59 2012 maxime ginters
##

CC	= cc
RM	= rm -f
AR	= ar rc
RAN	= ranlib
CP	= cp -f

CFLAGS	+= -I.

NAME	= libmy.a

HEADERS	= my.h

MAKEFILE= Makefile

SRCS	= my_find_prime_sup.c \
		my_getnbr_base.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_lowerize.c \
		my_param_to_tab.c \
		my_power_rec.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_putnbr_base_char.c \
		my_putnbr_base_size.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlcat.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		my_swap_char.c \
		my_upperize.c \
		my_realloc.c \
		my_strcpy.c \
		my_memset.c \
		my_sort_char_tab.c \
		my_power_it.c \
		my_str_to_wordtab_sep.c \
		clean_wordtab.c \
		xmalloc.c \
		my_substr.c \
		my_perror.c \
		my_printf.c \
		my_printf_funct.c \
		my_printf_funct2.c \
		my_printf_funct3.c \
		my_putnbr_base_long.c \
		my_atof.c \
		my_printf_param.c \
		my_putstr2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RAN) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
