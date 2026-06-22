##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling
##

SRC = my_putstr.c	\
	my_putchar.c	\
	word_array.c	\
	my_radar.c	\
	my_strncmp.c	\
	to_number.c	\
	main.c	\
	open_file.c	\
	pass_a.c	\
	pass_t.c	\

NAME = my_radar

LIB = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm -g3

all:
	gcc -o my_radar $(SRC) $(LIB)

clean:
	rm -f *~

fclean: clean
	rm -f *#
	rm my_radar

re: fclean all
