##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with my_top
##

SRC = *.c

NAME = my_sudo

all:
	gcc -o $(NAME) $(SRC) -g3 -lcrypt

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm $(NAME)

re: fclean all
