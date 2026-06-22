##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with my_top
##

SRC = *.c

NAME = my_top

all:
	gcc -o $(NAME) $(SRC) -lncurses -g3

clean:
	rm -f *~
	rm -f *#
	rm $(NAME)

fclean: clean
	rm coding-style-reports.log

re: fclean all
