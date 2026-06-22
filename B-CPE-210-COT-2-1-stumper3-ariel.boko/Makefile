NAME = minicut

SRC = *.c

OBJ = $(SRC:.c=.o)

MORE = .

all: $(SRC)
	gcc -o $(NAME) -g $(SRC) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *~
	rm -f *#
	rm -rf coding-style-reports.log
	rm -rf $(NAME)
	rm -rf a.out

re	: fclean all

push : fclean
	git add $(MORE); git commit -m "$(COMMIT)"; git push
