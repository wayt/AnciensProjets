##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Tue Mar 12 14:06:29 2013 maxime ginters
## Last update Tue Mar 12 14:15:07 2013 maxime ginters
##

MAKE	= make -C
CP		= cp -f
RM		= rm -f

MY_NM		= my_nm
MY_OBJDUMP	= my_objdump

F_MY_NM		= nm
F_MY_OBJDUMP	= objdump

all: nm objdump

clean:
	$(MAKE) $(F_MY_NM) clean
	$(MAKE) $(F_MY_OBJDUMP) clean

fclean:
	$(MAKE) $(F_MY_NM) fclean
	$(MAKE) $(F_MY_OBJDUMP) fclean
	$(RM) $(MY_NM)
	$(RM) $(MY_OBJDUMP)

re: fclean all

nm:
	$(MAKE) $(F_MY_NM)
	$(CP) $(F_MY_NM)/$(MY_NM) $(MY_NM)

objdump:
	$(MAKE) $(F_MY_OBJDUMP)
	$(CP) $(F_MY_OBJDUMP)/$(MY_OBJDUMP) $(MY_OBJDUMP)

.PHONY: all clean fclean re nm objdump

