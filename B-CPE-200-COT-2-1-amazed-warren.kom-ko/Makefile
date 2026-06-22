##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with 104neutrinos
##

SRC	=	src/*.c

TEST	=	src/my_strdup.c	\

OPT	=	-lm --coverage -lcriterion

all:
	gcc -o amazed $(SRC) -lm -g3

clean:
	rm -f src/*~
	rm -f src/*#
	rm -f *.o

fclean: clean
	rm -f amazed
	rm -f unit_test
	rm -f *.gcda
	rm -f *.gcno

re: fclean all clean

unit_tests: fclean all clean
	gcc -o unit_test $(TEST) tests/test_amazed.c $(OPT)

tests_run: unit_tests
	./unit_test
