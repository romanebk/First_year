/*
** EPITECH PROJECT, 2025
** dfgh
** File description:
** cv
*/

#include <criterion/criterion.h>

double arithmetic_mean(double n, double a, double nv);

Test(arithmetic_mean, calculates_mean)
{
    double a = arithmetic_mean(2.0, 5.0, 5.0);
    cr_expect(a == 5.0);
}
