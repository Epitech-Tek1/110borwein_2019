##
## EPITECH PROJECT, 2020
## AIA_n4s_2019 [WSL: Debian]
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2020
## Makefile-gen by Clement Muth [WSL: Debian]
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## ========================================================================== ##
PATH_DISPLAY		=	source/display/
SRC_DISPLAY		=


## ========================================================================== ##
PATH_ERROR		=	source/error/
SRC_ERROR		=


## ========================================================================== ##
PATH_INIT		=	source/init/
SRC_INIT		=


## ========================================================================== ##
SRC				=	source/main.c	\
					$(addprefix $(PATH_DISPLAY), $(SRC_DISPLAY))	\
					$(addprefix $(PATH_ERROR), $(SRC_ERROR))	\
					$(addprefix $(PATH_INIT), $(SRC_INIT))	\

BIN				= 	110borwein

CC				= 	gcc

OBJ 			= 	$(SRC:.c=.o)

RM				=	rm -rf

CFLAGS			=	-W -Wall

LDFLAGS			=	-Iinclude/ -Llibrary \
					-l_stat	\
					-l_string	\
					-l_maths	\

DFLAGS			=	-g -Wfatal-errors -Wpedantic -Wextra \
					-Wnonnull -Wmain -Wmissing-attributes -Wsequence-point -pg

all:			$(BIN)

$(BIN):			lib $(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(CFLAGS)
				@$(call SUCCESS, "----- Let\'s begin to play ! -----")

lib:
				@$(MAKE) -C library/string/
				@$(MAKE) -C library/stat/
				@$(MAKE) -C library/maths/

clean:
				$(RM) $(OBJ)
				@$(MAKE) -C library/string/ clean
				@$(MAKE) -C library/stat/ clean
				@$(MAKE) -C library/maths/ clean

fclean:			clean
				$(RM) $(BIN)
				@$(MAKE) -C library/string/ fclean
				@$(MAKE) -C library/stat/ fclean
				@$(MAKE) -C library/maths/ fclean

re_lib:
				@$(MAKE) -C library/string/ re
				@$(MAKE) -C library/stat/ re
				@$(MAKE) -C library/maths/ re

re:				fclean all

.PHONY:			 all, fclean, re, library

## ========================================================================== ##
%.o: %.c
				@(echo "\033[32m[Controller] :[\033[31m \c")
				@(echo "$@ \033[32m]\033[0m\033[0K")
				@($(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<)
				@(echo "\033[2F")