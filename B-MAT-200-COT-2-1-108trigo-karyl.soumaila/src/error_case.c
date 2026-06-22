/*
** EPITECH PROJECT, 2025
** function
** File description:
** cas d'erreur
*/

#include "../include/my.h"

int valid_coe(int ac)
{
    double i = sqrt(ac - 2);
    int j = sqrt(ac - 2);

    if (i - j > 0)
        return 84;
    return 0;
}

int check_input(int ac, char **av)
{
    if (strcmp(av[1], "SIN") == 0 || strcmp(av[1], "COS") == 0
        || strcmp(av[1], "SINH") == 0 ||
        strcmp(av[1], "COSH") == 0
        || strcmp(av[1], "EXP") == 0) {
    } else
        return 84;
    return 0;
}

int check_arg(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') ||
            (str[i] >= '0' && str[i] <= '9')) {
        } else
            exit(84);
    }
    return 0;
}

int error_case(int ac, char **av)
{
    int i = 2;
    int j = 0;

    for (; av[i] != NULL; i++)
        check_arg(av[i]);
    return 0;
}
