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

void free_function(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

double calculate(double x, int ac, char **av)
{
    double res = 1.0;
    int i = 1;
    int id = 0;
    double *tb;

    tb = malloc(ac * sizeof(double));
    if (!tb)
        exit(84);
    for (; av[i] != NULL && av[i + 1] != NULL; i = i + 2) {
        if (parse_poly(av[i + 1], x) > 0 ||
            parse_poly(av[i + 1], x) < 0) {
            tb[id] = (parse_poly(av[i], x) / parse_poly(av[i + 1], x));
            res = res * tb[id];
            id++;
        } else
            exit(84);
    }
    free(tb);
    return res;
}
