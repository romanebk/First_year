/*
** EPITECH PROJECT, 2024
** FUNCTION
** File description:
** Verify argument
*/

#include "../include/my.h"

int count_vir(char *str)
{
    int i = 0;
    int	j = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.' )
            j++;
    }
    return j;
}

int check_arg(char *str)
{
    int i = 0;
    int n = 0;

    n = count_vir(str);
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' || (str[i] == '.' && n == 1 && str[i + 1] >= '0' && str[i + 1] <= '9')) {
        } else
            exit(84);
    }
    return 0;
}

int check_vir(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
        } else
            exit(84);
    }
    return 0;
}
