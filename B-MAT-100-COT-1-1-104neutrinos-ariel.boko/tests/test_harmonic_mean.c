/*
** EPITECH PROJECT, 2025
** gh
** File description:
** fds
*/
#include <criterion/criterion.h>

double harmonic_mean(double h, double n, double nv);

Test(harmonic_mean, calculates_harmonic_mean)
{
    float a = harmonic_mean(47.2, 45.0, 15.0);
    cr_expect(a != 0);
}
