/*
** EPITECH PROJECT, 2025
** game
** File description:
** x0
*/

#include "../my.h"

char **remplace(char **tab, char *line, char c)
{
    char **table = NULL;
    int x = 0;
    int y = 0;

    if (check(line) == 0)
        table = str_to_word_array(line, ' ', 0);
    if (count(table) != 2)
        return NULL;
    x = atoi(table[1]);
    y = atoi(table[0]);
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (i == x && j == y)
                tab[x][y] = c;
        }
    }
    return tab;
}
