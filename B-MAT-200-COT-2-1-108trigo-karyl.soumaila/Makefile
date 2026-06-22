##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with 104neutrinos
##

SRC	=	src/*.c

TEST =  src/usage.c	\
		src/error_case.c	\

OPT = -lm --coverage -lcriterion

all:
	gcc -o 108trigo $(SRC) -lm -g3

clean:
	rm -rf *~
	rm -rf *#
	rm -rf *.o

fclean: clean
	rm -rf 108trigo
	rm -rf unit_test
	rm -rf *.gcda
	rm -rf *.gcno

re: fclean all clean

unit_tests: fclean all clean
	gcc -o unit_test $(TEST) tests/test_trigo.c $(OPT)

tests_run: unit_tests
	./unit_test
