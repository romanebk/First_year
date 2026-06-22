/*
** EPITECH PROJECT, 2024
** word_array
** File description:
** shortcut
*/

#include "../my.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int word(char *str, char c)
{
    int a = my_strlen(str) - 1;
    int i = 0;

    for (int b = 0; b <= a; b++) {
        if (str[b] != c && str[b + 1] == c)
            i++;
    }
    return i + 1;
}

int array(char *str, char s, int i)
{
    int a = my_strlen(str) - 1;
    int c = 0;

    for (; str[i] != s && i <= a; i++)
        c++;
    return c;
}

char **cond(char **table, int car, int z, int y)
{
    table[z][y] = '\0';
    table[car] = NULL;
    return table;
}

array_t my_array(char *str, char c, int i)
{
    array_t arr;

    arr.len = array(str, c, 0);
    arr.car = word(str, c);
    arr.z = 0;
    arr.y = 0;
    arr.table;
    return arr;
}

char **str_to_word_array(char *str, char c, int i)
{
    array_t arr = my_array(str, c, i);
    int k = 0;

    arr.table = malloc(sizeof(char *) * (arr.car + 1));
    arr.table[0] = malloc(sizeof(char) * (arr.len + 1));
    for (; i <= (my_strlen(str) - 1); i++) {
        if (str[i] == c) {
            arr.table[arr.z][arr.y] = '\0';
            arr.z++;
            arr.y = 0;
            arr.len = array(str, c, i + 1);
            arr.table[arr.z] = malloc(sizeof(char) * (arr.len + 1));
        } else {
            arr.table[arr.z][arr.y] = str[i];
            arr.y++;
        }
    }
    cond(arr.table, arr.car, arr.z, arr.y);
}
