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

int display(int ac, char **av)
{
    double start = 0.0;
    double end = 1.001;

    for (; start <= end; start = start + 0.001)
        printf("%.3f -> %.5f\n", start, calculate(start, ac, av));
    return 0;
}
