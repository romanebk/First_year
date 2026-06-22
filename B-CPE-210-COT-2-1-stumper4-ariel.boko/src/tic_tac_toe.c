/*
** EPITECH PROJECT, 2025
** STUMPER 2
** File description:
** boogle
*/

#include "../my.h"

char **alloc_arr(int size)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * (size + 1));

    for (; i < size; i++)
        tab[i] = malloc(sizeof(char) * (size + 1));
    tab[i] = NULL;
    return tab;
}

void print_grid(char **tab, int def)
{
    printf("+");
    for (int i = 0; i < def; ++i)
        printf("-");
    printf("+\n");
    for (int i = 0; tab[i] != NULL; i++) {
        printf("|");
        for (int j = 0; j < def; j++) {
            printf("%c", tab[i][j]);
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < def; ++i)
        printf("-");
    printf("+\n");
    return;
}

char **create_grid(char a, int def)
{
    int i = 0;
    int j = 0;
    char **tab = NULL;

    tab = alloc_arr(def);
    for (; tab[i] != NULL; i++) {
        for (; j < def; j++)
            tab[i][j] = a;
        j = 0;
    }
    return tab;
}
/*
int main()
{
    char c;
    char **tab = create_grid('b', 4);
    print_grid(tab, 4);
    return 0;
}
*/
