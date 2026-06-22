/*
** EPITECH PROJECT, 2025
** str_is_number
** File description:
** function
*/

#include "my.h"

int str_isnumber(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return -1;
    }
    return 1;
}
