/*
** EPITECH PROJECT, 2025
** function
** File description:
** that skip #
*/

#include "../include/my.h"

int verify_hashtag(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#')
            j++;
    }
    return j;
}

void cut_slip_hashtag(char *str)
{
    char *tmp;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#' && verify_hashtag(str) == 1) {
            tmp = my_strtok(str, "#");
            str = my_strdup(tmp);
        }
    }
}

char **slip_hashtag(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        cut_slip_hashtag(tab[i]);
    }
    return tab;
}
