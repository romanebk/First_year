##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling
##

SRC	=	*.c

NAME	=	my_world

FLAGS1	=	-lcsfml-graphics -lcsfml-system -g3

FLAGS2	=	-lcsfml-window -lcsfml-audio -lm

all:
	gcc -o $(NAME) $(SRC) $(FLAGS1) $(FLAGS2)

clean:
	rm -f *~

fclean: clean
	rm -f *#
	rm my_world

re: fclean all
