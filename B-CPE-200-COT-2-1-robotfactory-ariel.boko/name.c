/*
** EPITECH PROJECT, 2025
** name
** File description:
** name
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *name(char *str)
{
    char *nam;
    int i = 0;

    for (; str[i] != '.'; i++);
    nam = malloc(sizeof(char) * my_s(str) + 3);
    if (!nam)
        return NULL;
    my_strncpy(nam, str, i);
    my_strcat(nam, ".cor");
    if (nam == NULL || my_s(nam) == 0)
        return NULL;
    return nam;
}
