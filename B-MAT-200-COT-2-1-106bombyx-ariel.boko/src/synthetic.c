/*
** EPITECH PROJECT, 2025
** synthetic
** File description:
** calcul
*/

#include "../include/my.h"

void generate_synthetic_data(double n, double i0, double i1)
{
    double x = 0.0;

    for (double k = 1.0; k <= 4.0; k = k + 0.01) {
	x = n;
        if (n > 1000)
            x = 0;
        for (int i = 1; i <= i1; i++) {
            if (x <= 1000) {
                if (i >= i0)
                    printf("%.2f %.2f\n", k, x);
            }
            x = (k * x) * ((1000 - x) / 1000);
        }
    }
}
