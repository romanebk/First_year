/*
** EPITECH PROJECT, 2025
** fd
** File description:
** fd
*/

#include <criterion/criterion.h>

double standard_deviation(double a, double nv, double n, double sd);

Test(standard_deviation, calculates_std)
{
    float a = standard_deviation(297514.0, 299042.0, 12000.0, 4363.0);
    cr_expect(a != 0);
}
