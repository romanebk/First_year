/*
** EPITECH PROJECT, 2025
** fghjklm
** File description:
** lkjhgfd
*/
#include "my.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double root_mean_square(double n, double sd, double a, double nv)
{
    double rms_pre_po = 0.0;
    double stock_x_r = 0.0;
    double rms_new = 0.0;

    rms_pre_po = pow(sd, 2) + pow(a, 2);
    stock_x_r = rms_pre_po * n + nv * nv;
    rms_new = sqrt(stock_x_r / (n + 1));
    return rms_new;
}
