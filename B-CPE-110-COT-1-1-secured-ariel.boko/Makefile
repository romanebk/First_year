##
## EPITECH PROJECT, 2025
## oigdza
## File description:
## dzad
##


SRC	=	*.c

NAME	=	dau

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c *.c
	ar rc libhashtable.a *.o

clean:
	rm -f $(OBJ)
	rm -f *#

fclean:	clean
	rm -f $(NAME) *.o
	rm -f libhashtable.a
	rm -f *~

re:	fclean all

auteur:
	echo $(USER) > auteur
