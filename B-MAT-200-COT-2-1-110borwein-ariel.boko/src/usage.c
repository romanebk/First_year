/*
** EPITECH PROJECT, 2024
** Maths
** File description:
** 110 borwein
*/

#include "../include/my.h"

int usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        printf("USAGE\n");
        printf("    ./110borwein n\n\n");
        printf("DESCRIPTION\n");
        printf("    n  constant defining the integral to be computed\n");
    } else
        return 84;
    return 0;
}
