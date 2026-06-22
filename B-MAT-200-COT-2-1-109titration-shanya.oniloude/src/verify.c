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
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' ||
            str[i - 1] >= '0' && str[i - 1] <= '9' &&
            str[i] == '.' && str[i + 1] >= '0' &&
            str[i + 1] <= '9') {
            res = 0;
        } else {
            res = 1;
            break;
        }
        i++;
    }
    return res;
}
