##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling
##

SRC = main.c       \
	 display.c	\
	menu.c	\
	my_hunter.c	\
	my_putstr.c	\
	my_putchar.c	\

NAME = my_hunter

all:
	gcc -o my_hunter $(SRC) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
clean:
	rm -f *~

fclean: clean
	rm -f *#
	rm my_hunter

re: fclean all
