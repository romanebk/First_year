/*
** EPITECH PROJECT, 2025
** STUMPER 2
** File description:
** boogle
*/

#include "my.h"

int grid_size(char *str, int def)
{
    int size = def * def;

    if (size == my_strlen(str))
        return def;
    return -1;
}

char **alloc_arr(int size)
{
    char **tab = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i++) {
        tab[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j < size; j++)
            tab[i][j] = '\0';
    }
    return tab;
}

void print_grid(char **tab, int def)
{
    for (int i = 0; i != def * 2 + 2; ++i)
        printf("+");
    printf("+\n");
    for (int i = 0; tab[i]; i++) {
        printf("| ");
        for (int j = 0; tab[i][j]; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("|\n");
    }
    for (int i = 0; i != def * 2 + 2; ++i)
        printf("+");
    printf("+\n");
    return;
}

char **create_grid(char *str, int def)
{
    char **tab = NULL;
    int size = grid_size(str, def);
    int i = 0;
    int j = 0;

    if (size == -1)
        return NULL;
    tab = alloc_arr(size);
    for (int a = 0; str[a]; a++) {
        tab[i][j] = str[a];
        j++;
        if (j == size) {
            tab[i][j] = '\0';
            i++;
            j = 0;
        }
    }
    tab[i] = NULL;
    return tab;
}
