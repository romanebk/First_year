/*
** EPITECH PROJECT, 2025
** function
** File description:
** compute the midpoint of a intergral
*/

#include "../include/my.h"

void midpoint_function(int n)
{
    double h = (0 + 5000.0) / 10000;
    double sum = 0.0;
    double x = 0.0;

    for (int i = 0; i < 10000; i++) {
        x = i * h + h / 2.0;
        sum = sum + borwein_function(x, n);
    }
    printf("Midpoint:\nI%d = %.10f\n", n, sum * h);
    printf("diff = %.10f\n\n", fabs(sum * h - M_PI / 2.0));
}
