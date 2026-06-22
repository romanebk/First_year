/*
** EPITECH PROJECT, 2025
** dsdd
** File description:
** sdf
*/
#include "my.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double standard_deviation(double a, double nv, double n, double sd)
{
    double new_a = arithmetic_mean(n, a, nv);
    double new_sd = 0.0;
    double stock_x_sd_p = 0.0;
    double stock_x_sd_n = 0.0;

    stock_x_sd_p = (pow(a, 2) + pow(sd, 2)) * n;
    stock_x_sd_n = stock_x_sd_p + pow(nv, 2);
    new_sd = sqrt(((stock_x_sd_n) / (n + 1)) - (pow(new_a, 2)));
    return new_sd;
}
