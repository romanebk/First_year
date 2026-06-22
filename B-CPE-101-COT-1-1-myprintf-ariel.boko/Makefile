##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Compiling my libmy
##

SRC = my_printf.c	\
	my_put_nbr.c	\
	my_put_nbr_base_o.c	\
	my_put_nbr_unsigned.c	\
	my_putstr.c	\
	my_putchar.c	\
	my_put_nbr_p.c	\
	my_put_nbr_xg.c	\
	my_put_nbr_xp.c	\
	my_put_nbr_f.c	\
	my_put_nbr_fe.c	\
	my_put_nbr_e.c	\
	my_put_nbr_fg.c	\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
