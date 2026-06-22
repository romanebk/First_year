/*
** EPITECH PROJECT, 2024
** FUNCTION
** File description:
** Verify argument
*/

#include "../include/my.h"

int check_arg(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
        } else
            return 1;
    }
    return 0;
}
