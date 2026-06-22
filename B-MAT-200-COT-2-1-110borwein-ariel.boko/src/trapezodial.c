/*
** EPITECH PROJECT, 2025
** function
** File description:
** returns the approximation of the Borwein integral
*/

#include "../include/my.h"

void trapezoidal_function(int n)
{
    double x = 0.0;
    double h = (0 + 5000.0) / 10000;
    double sum = (borwein_function(0.0, n) + borwein_function(5000, n)) / 2;

    for (int i = 1; i < 10000; i++) {
        x = i * h;
        sum += borwein_function(x, n);
    }
    printf("Trapezoidal:\nI%d = %.10f\n", n, sum * h);
    printf("diff = %.10f\n\n", fabs(sum * h - M_PI / 2.0));
}
