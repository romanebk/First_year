##
## EPITECH PROJECT, 2025
## 106bombyx
## File description:
## make some task
##

FILE	=	src/main.c	\
		src/free.c	\
		src/mind.c	\
		src/usage.c	\
		src/textcount.c	\
		src/tree_fctn.c	\

OBJ	=	$(FILE:*.c=*.o)

BIN	=	text_count

TESTS_FILE	=	src/mind.c	\
			src/my_strlen.c	\

all	:	$(OBJ)
		gcc -o $(BIN) $(OBJ) -lm -g3

clean	:
		rm -rf *~ src/*~ include/*~
		rm -rf *.o src/*.o

fclean	:	clean
		rm -rf *# src/*# include/*#
		rm -f *.gcno
		rm -f *.gcda
		rm -f unit_tests
		rm -rf $(BIN) coding-style-reports.log

re	:	fclean all

cod-style	:
			coding-style .
			cat coding-style-reports.log

unit_tests	:	fclean
		gcc -o unit_tests tests/*.c $(TESTS_FILE) --coverage -lcriterion -g3

tests_run	:
			./unit_tests
