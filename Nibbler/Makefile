##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Wed Mar 20 22:17:40 2013 vincent leroy
## Last update Sat Mar 23 16:13:30 2013 fabien casters
##

SDL		= libraries/sdl/

OPENGL		= libraries/opengl/

NCURSES		= libraries/ncurses/

CORE	= core/

MAKE	= make -C

all: core sdl opengl ncurses

core:
	$(MAKE) $(CORE)

sdl:
	$(MAKE) $(SDL)

opengl:
	$(MAKE) $(OPENGL)

ncurses:
	$(MAKE) $(NCURSES)
clean:
	$(MAKE) $(CORE) clean
	$(MAKE) $(SDL) clean
	$(MAKE) $(OPENGL) clean
	$(MAKE) $(NCURSES) clean

fclean:
	$(MAKE) $(CORE) fclean
	$(MAKE) $(SDL) fclean
	$(MAKE) $(OPENGL) fclean
	$(MAKE) $(NCURSES) fclean

re:
	$(MAKE) $(CORE) re
	$(MAKE) $(SDL) re
	$(MAKE) $(OPENGL) re
	$(MAKE) $(NCURSES) re

.PHONY: all core sdl opengl ncurses clean fclean re
