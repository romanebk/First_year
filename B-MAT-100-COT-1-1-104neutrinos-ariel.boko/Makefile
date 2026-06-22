##
## EPITECH PROJECT, 2024
## makefile
## File description:
## compiling with 104neutrinos
##

SRC	=	usage.c	\
		neutrinos.c	\

SRC2	=	tests/test_harmonic_mean.c	\
		tests/test_mean.c	\
		tests/test_sd.c	\
		tests/test_rms.c	\

SRC3	=	mean.c	\
		harm_mean.c	\
		std.c	\
		rms.c

all:
	gcc -o 104neutrinos $(SRC) -lm -g3

unit_tests:
	gcc -o unit_tests $(SRC3) $(SRC2) --coverage -lcriterion -lm

test_run:
	./unit_tests

clean:
	rm -f *~

fclean: clean
	rm 104neutrinos
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

re: fclean all
