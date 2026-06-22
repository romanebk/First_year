##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC	=	src/*.c

LIB	=	libcuddle.a

all:
	gcc -c $(SRC) -I/include -g3
	ar rcs $(LIB) *.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f *~
	rm -f *#
	rm -f coding-style-reports.log

fclean:	clean
	rm -f $(LIB)

re:	fclean all
