##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRCS = $(wildcard *.c)

NAME = asm

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS) -g3

clean:
	rm -f $(OBJS)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
