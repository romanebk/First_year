/*
** EPITECH PROJECT, 2025
** my_str
** File description:
** my_str
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

int count_sep(char *str)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n') {
            i++;
        }
    }
    return i + 1;
}

char **aloc(char **tab, char *str)
{
    int r = 0;

    r = count_sep(str);
    tab = malloc(sizeof(char *) * r);
    if (!tab)
        return NULL;
    for (int i = 0; i < count_sep(str); i++)
        tab[i] = malloc(sizeof(char) * 50);
    return tab;
}

char **my_str(char *s)
{
    int t = 0;
    int y = 0;
    char **tab = NULL;

    tab = aloc(tab, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            tab[t][y] = s[i];
            y++;
        } else if (s[i] == ' ' || s[i] == '\t' || my_s(tab[t]) != 0) {
            tab[t][y] = '\0';
            t++;
            y = 0;
            continue;
        }
    }
    tab[t + 1] = NULL;
    return tab;
}
