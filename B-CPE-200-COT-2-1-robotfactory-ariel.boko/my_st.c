/*
** EPITECH PROJECT, 2025
** my_st
** File description:
** my_st
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"

char *error(char *buf)
{
    if (my_s(buf) == 0)
        return NULL;
    check_header(buf);
}

int count_se(char *str, char c)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == c || str[j] == '\t')
            i++;
    }
    return i + 1;
}

char **alloc(char **tab, char *str, char c)
{
    int r = 0;

    r = count_se(str, c);
    tab = malloc(sizeof(char *) * r);
    if (!tab)
        return NULL;
    for (int i = 0; i < count_se(str, c); i++)
        tab[i] = malloc(sizeof(char) * 50);
    return tab;
}

char **my_st(char *str, char c)
{
    int t = 0;
    int y = 0;
    char **tab = NULL;

    error(str);
    tab = alloc(tab, str, c);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && str[i] != '\t') {
            tab[t][y] = str[i];
            y++;
        }
        if (str[i] == c || str[i] == '\t' && my_s(tab[t]) != 0) {
            tab[t][y] = '\0';
            t++;
            y = 0;
            continue;
        }
    }
    tab[t + 1] = NULL;
    return tab;
}
