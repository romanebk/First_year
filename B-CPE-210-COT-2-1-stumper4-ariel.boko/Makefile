##
## EPITECH PROJECT, 2024
## my_top.c
## File description:
## makefile
##

SRC	=	src/*.c	\
		system_command/*.c \

BIN 	=	tictactoe

TESTS_FILES =	system_command/*.c

TESTS =	tests/*.c

all:	$(BIN)

$(BIN):	$(SRC)
	gcc -o $(BIN) $(SRC) -g3

clean:
	rm -f $(BIN)

unit_tests: fclean all clean
	gcc -o unit_tests $(TESTS) $(TESTS_FILES) -lcriterion --coverage -g3

tests_run: unit_tests
	./unit_tests --verbose

fclean:	clean
	rm -f *~
	rm -f *#
	rm -f include/*~
	rm -f src/*~
	rm -f tests/*~
	rm -f src/*#
	rm -f system_command/*~
	rm -f coding-style-reports.log
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

re:	fclean all
