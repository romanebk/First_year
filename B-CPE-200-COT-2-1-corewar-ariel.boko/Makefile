##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with 104neutrinos
##

SRC	=	src/*.c


all:
	gcc -o corewar $(SRC) -lm -g3 -lncurses

clean:
	rm -f include/*~
	rm -f include/*#
	rm -f src/*~
	rm -f src/*#
	rm -f *~
	rm -f *#

fclean: clean
	rm -rf corewar

re: fclean all clean
