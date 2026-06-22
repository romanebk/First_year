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

int counter(char *str)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*')
            count++;
    }
    return count;
}

double parse_poly(char *str, double x)
{
    double result = 0.0;
    int index = 0;
    int *coefficients;
    char **tab = str_array(str, '*');
    int count = counter(str);

    coefficients = malloc(((count * 2) + 1) * sizeof(int));
    if (!coefficients)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        if (check_arg(tab[i]) == 84)
            exit(84);
        coefficients[index] = atoi(tab[i]);
        coefficients[index + 1] = i;
        result = result + (coefficients[i] * pow(x, coefficients[i + 1]));
        index++;
    }
    free_function(tab);
    free(coefficients);
    return result;
}
