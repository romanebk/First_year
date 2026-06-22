/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/

#include "my.h"

int count_separator(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            count++;
        i++;
    }
    return count;
}

int nb_char(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] != c)
            count++;
        i++;
    }
    return count;
}

char *free_function(char **tab, int i)
{
    for (int j = 0; j <= i; j++)
        free(tab[j]);
    free(tab);
    return NULL;
}

char *error_case_three(int nb_column, int nb_line, char **tab)
{
    if (tab == NULL)
        return NULL;
    for (int i = 0; i < nb_line; i++) {
        tab[i] = malloc(sizeof(char) * (nb_column + 1));
        if (tab[i] == NULL) {
            free_function(tab, i);
        }
    }
}

char **my_str_to_word_array(char *str, char c)
{
    int a = 0;
    int b = 0;
    int nb_line = count_separator(str, c) + 1;
    int nb_column = nb_char(str, c) + 1;
    char **tab = malloc(sizeof(char *) * (nb_line + 1));

    error_case_three(nb_column, nb_line, tab);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            tab[a][b] = '\0';
            a++;
            b = 0;
        } else {
            tab[a][b] = str[i];
            b++;
        }
    }
    tab[a] = NULL;
    return tab;
}
