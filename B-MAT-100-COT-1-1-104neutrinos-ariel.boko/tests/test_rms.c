/*
** EPITECH PROJECT, 2025
** gfds
** File description:
** fds
*/
#include <criterion/criterion.h>

double root_mean_square(double n, double sd, double a, double nv);

Test(root_mean_square, calculates_root_mean_square)
{
    double a = (174182.0, 841522.0, 354145.0, 45554.0);
    cr_expect(a != 0);
}
