/*
** EPITECH PROJECT, 2025
** jk
** File description:
** ds
*/
#include "my.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double harmonic_mean(double h, double n, double nv)
{
    double stock_x_h = 0.0;
    double new_h = 0.0;

    stock_x_h = (n / h) + (1 / nv);
    new_h = (n + 1) / stock_x_h;
    return new_h;
}
