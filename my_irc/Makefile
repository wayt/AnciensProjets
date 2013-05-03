##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sun Apr 14 19:14:09 2013 maxime ginters
## Last update Sun Apr 14 19:20:00 2013 maxime ginters
##

MAKE	= make -C
CP	= cp -f

CLIENT_DIR	= src_client
CLIENT_BIN	= src_client/client

SERVEUR_DIR	= src_serveur
SERVEUR_BIN	= src_serveur/serveur

all: client serveur

client:
	$(MAKE) $(CLIENT_DIR)
	$(CP) $(CLIENT_BIN) .

serveur:
	$(MAKE) $(SERVEUR_DIR)
	$(CP) $(SERVEUR_BIN) .

clean:
	$(MAKE) $(CLIENT_DIR) clean
	$(MAKE) $(SERVEUR_DIR) clean

fclean:
	$(MAKE) $(CLIENT_DIR) fclean
	$(MAKE) $(SERVEUR_DIR) fclean

re: fclean all

.PHONY: all clean fclean re client serveur

