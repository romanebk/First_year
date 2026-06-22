/*
** EPITECH PROJECT, 2025
** function
** File description:
** the borwein integral function
*/

#include "../include/my.h"

double borwein_function(double x, int n)
{
    double den = 0.0;
    double product = 1.0;

    if (x == 0.0)
        return 1.0;
    for (int k = 0; k <= n; k++) {
        den = x / ((2 * k) + 1);
        product = product * sin(den) / den;
    }
    return product;
}
