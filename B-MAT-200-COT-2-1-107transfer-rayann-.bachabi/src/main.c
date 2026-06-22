/*
** EPITECH PROJECT, 2025
** 105 demography
** File description:
** main.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/my.h"
#include <math.h>

int check(char *str)
{
    int j = 0;

    for (; str[j] != '\0'; j++);
    if (str[0] == '*' || str[j - 1] == '*')
        exit(84);
    return 0;
}

int error_case(int ac, char **av)
{
    int i = 1;
    int j = 0;

    for (; av[i] != NULL; i++)
        check(av[i]);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage(ac, av);
        return 0;
    }
    if (ac < 3)
        exit(84);
    if (ac % 2 == 1) {
        error_case(ac, av);
        display(ac, av);
    } else
        exit(84);
    return 0;
}
