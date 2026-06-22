/*
** EPITECH PROJECT, 2025
** pop
** File description:
** ulation
*/

#include "../include/my.h"

void calcul_population(double n, double k)
{
    double x = 0.0;

    x = n;
    for (int i = 1; i <= 100; i++) {
        printf("%d %.2f\n", i, x);
        if (x > 1000)
            x = 1000;
        if (x < 0)
            x = 0;
        x = k * x * ((1000 - x) / 1000);
    }
}
