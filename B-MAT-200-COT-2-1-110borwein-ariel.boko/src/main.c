/*
** EPITECH PROJECT, 2025
** 105 demography
** File description:
** main.
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    int n = 0;

    if (ac != 2)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage(ac, av);
        return 0;
    }
    n = atoi(av[1]);
    if (check_arg(av[1]) == -1 || n < 0)
        return 84;
    midpoint_function(n);
    trapezoidal_function(n);
    simpson_function(n);
    return 0;
}
