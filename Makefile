##
## EPITECH PROJECT, 2020
## AIA_n4s_2019 [WSL: Debian]
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## ========================================================================== ##
PATH_CONTROLLER		=	source/controller/
SRC_CONTROLLER		=	error.c	\
						init.c	\
						process.c	\
						display.c


## ========================================================================== ##
SRC				=	source/main.c	\
					$(addprefix $(PATH_CONTROLLER), $(SRC_CONTROLLER))

BIN				= 	110borwein

CC				= 	gcc

OBJ 			= 	$(SRC:.c=.o)

RM				=	rm -rf

CFLAGS			=	-W -Wall

LDFLAGS			=	-Iinclude/ -Llibrary \
					-l_stat	\
					-l_maths	\
					-l_assert	\
					-l_string	\
					-lm	\


all:			$(BIN)

$(BIN):			lib $(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(CFLAGS)
				@$(call SUCCESS, "----- Let\'s begin to play ! -----")

lib:
				@$(MAKE) -C library/string/
				@$(MAKE) -C library/stat/
				@$(MAKE) -C library/maths/
				@$(MAKE) -C library/assert/

clean:
				$(RM) $(OBJ)
				@$(MAKE) -C library/string/ clean
				@$(MAKE) -C library/stat/ clean
				@$(MAKE) -C library/maths/ clean
				@$(MAKE) -C library/assert/ clean

fclean:			clean
				$(RM) $(BIN)
				@$(MAKE) -C library/string/ fclean
				@$(MAKE) -C library/stat/ fclean
				@$(MAKE) -C library/maths/ fclean

re_lib:
				@$(MAKE) -C library/string/ re
				@$(MAKE) -C library/stat/ re
				@$(MAKE) -C library/maths/ re
				@$(MAKE) -C library/assert/ re

re:				fclean all

.PHONY:			 all, fclean, re, library

## ========================================================================== ##
%.o: %.c
				@(echo "\033[32m[Controller] :[\033[31m \c")
				@(echo "$@ \033[32m]\033[0m\033[0K")
				@($(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<)
				@(echo "\033[2F")