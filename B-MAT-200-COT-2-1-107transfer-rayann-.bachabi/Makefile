##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with 104neutrinos
##

SRC	=	src/*.c

TEST =  src/usage.c	\
		src/verify.c	\

OPT = -lm --coverage -lcriterion

all:
	gcc -o 107transfer $(SRC) -lm -g3

clean:
	rm -rf *~
	rm -rf *#
	rm -rf *.o

fclean: clean
	rm -rf 107transfer
	rm -rf unit_test

re: fclean all clean

unit_tests: fclean all clean
	gcc -o unit_test $(TEST) tests/test_transfer.c $(OPT)

tests_run: unit_tests
	./unit_test
