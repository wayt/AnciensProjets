##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Mon Dec 03 15:08:54 2012 vincent leroy
## Last update Sun Dec 16 19:16:55 2012 vincent leroy
##

MAKE	= make -C

ASM	= asm/

CORE	= corewar/

all: asm core

asm:
	$(MAKE) $(ASM)

core:
	$(MAKE) $(CORE)

clean:
	$(MAKE) $(ASM) clean
	$(MAKE) $(CORE) clean

re: clean all

.PHONY: all asm core clean re
