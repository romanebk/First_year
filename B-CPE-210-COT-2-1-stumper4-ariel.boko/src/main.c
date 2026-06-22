/*
** EPITECH PROJECT, 2025
** STUMPER 4
** File description:
** boogle
*/

#include "../my.h"

char printf_player(int i, char x, char o)
{
    char c;

    if (i % 2 != 0) {
        printf("\nPlayer 1> ");
        c = x;
    } else if (i % 2 == 0) {
        printf("\nPlayer 2> ");
        c = o;
    }
    return c;
}

int launch_loop(int def, char x, char o)
{
    char c;
    int i = 1;
    char **tab = NULL;
    char **table = create_grid(' ', def);
    char **tmp = NULL;
    char *line = NULL;
    size_t size = 0;

    print_grid(create_grid(' ', def), def);
    while (1) {
        c = printf_player(i, x, o);
        if (getline(&line, &size, stdin) == -1)
            return 0;
        line[my_strlen(line) - 1] = '\0';
        tab = remplace(table, line, c);
        print_grid(tab, def);
        i++;
        table = tab;
    }
    return 0;
}

int main(int ac, char **av)
{
    char x;
    char o;

    if (ac == 1) {
        launch_loop(3, 'X', 'O');
        return 0;
    }
    return 0;
}
