##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## stumper 2
##


SRCS	=	*.c\
		utilities/*.c\

NAME	=	boogle

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRCS) -lm -g3

clean:
	rm -f $(OBJS)

fclean	:
	rm -f $(NAME) $(OBJS)
	rm -f *~
	rm -f *#
	rm -f *gcno
	rm -f *gcda

re	:	fclean all

tests_run	:
	gcc -o test tests/*.c -lcriterion -lm
	./test
