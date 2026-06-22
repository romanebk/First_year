/*
** EPITECH PROJECT, 2025
** efefé
** File description:
** édfé"dfé"f
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

char last_char(char *str)
{
    int i = 0;

    i = my_strlen(str);
    return str[i];
}

int hash(char *key, int len)
{
    int hash = 5381;
    int i = 0;
    int j = 0;
    char l = last_char(key);

    if (!key || len <= 0 || my_strlen(key) == 0)
        return 84;
    for (i = 0; key[i]; i++) {
        for (j = i; j > 0; j--)
            hash = hash * 31 + (key[i] * (l - 65));
    }
    if (hash < 0)
        hash = (hash) * (-1);
    return hash;
}
