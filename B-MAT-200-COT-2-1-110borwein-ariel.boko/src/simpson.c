/*
** EPITECH PROJECT, 2025
** function
** File description:
** returns the approximation of the Borwein integral
*/

#include "../include/my.h"

void simpson_function(int n)
{
    double a = 0.0;
    double b = 0.0;
    double simp = 0.0;
    double x;

    for (a = 0; a + 0.5 <= 5000; a += 0.5) {
        b = a + 0.5;
        simp += (((b - a) / 6) * (borwein_function(a, n) +
        ((4 * borwein_function(((a + b) / 2), n)) +
        (borwein_function(b, n)))));
    }
    printf("Simpson:\nI%d = %.10f\n", n, simp);
    printf("diff = %.10f\n", fabs(simp - (M_PI / 2.0)));
}
