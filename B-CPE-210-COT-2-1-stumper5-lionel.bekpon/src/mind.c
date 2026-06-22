/*
** EPITECH PROJECT, 2025
** error.case
** File description:
** shortcut
*/

#include "../include/my.h"

int count_occur(char *str, char c)
{
    int i = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            j++;
    }
    return j;
}

int find_char(char *str, char c)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

char *filtre_str(char *str)
{
    int i = 0;
    int j = 0;
    char *tab = NULL;

    tab = malloc(sizeof(char) * (strlen(str) + 1));
    if (!tab)
        return NULL;
    tab[j] = str[i];
    for (i = 1; i < (strlen(str) + 1); i++)
        tab[i] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        if (find_char(tab, str[i]) == 0) {
            j++;
            tab[j] = str[i];
            continue;
        }
    }
    return tab;
}

/*int print_occur1(char *ptr, char *want)
{
    int b = 0;
    char *tab = filtre_str(want);

    for (int i = 0; tab[i] != '\0'; i++) {
        b = count_occur(ptr, tab[i]);
        printf("%c:%d\n", tab[i], b);
    }
    return 0;
}
*/
