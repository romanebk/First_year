##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with my_top
##

SRC	=	*.c

NAME	=	mysh

TEST	=	my_strcmp.c	\
		count_sep.c	\
		my_strcpsn.c	\
		my_strlen.c	\
		my_strdup.c	\

OPT	=	-lm --coverage -lcriterion

all:
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f *#

fclean:	clean
		rm -rf unit_test
		rm -rf *.gcno
		rm -rf *.gcda

re:	fclean all

unit_tests:	fclean all clean
		gcc -o unit_test $(TEST) tests/test_mysh.c $(OPT)

tests_run:	unit_tests
		./unit_test
