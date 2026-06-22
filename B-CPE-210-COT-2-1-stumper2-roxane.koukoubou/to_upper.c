/*
** EPITECH PROJECT, 2025
** to_lower
** File description:
** function
*/

#include "my.h"

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
    return c;
}

int my_str_islower(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return -1;
    }
    return 1;
}
