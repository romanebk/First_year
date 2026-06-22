##
## EPITECH PROJECT, 2024
## make
## File description:
## file
##

SRC	=	src/*.c

TEST	=	src/usage.c	\
		src/verify.c	\

OPT	=	-lm --coverage -lcriterion

NAME	=	109titration

all:
	gcc $(SRC) -o $(NAME) -lm -g3

clean:
	rm -f *#
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f unit_test
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all

unit_tests:	fclean all clean
		gcc -o unit_test $(TEST) tests/test_titration.c $(OPT)

tests_run:	unit_tests
		./unit_test
