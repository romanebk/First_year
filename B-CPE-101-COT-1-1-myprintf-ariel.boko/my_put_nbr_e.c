/*
** EPITECH PROJECT, 2024
** dfghjklm
** File description:
** fghjklm
*/

#include <stdio.h>
#include "include/my.h"

double exp_one(double nb, int a)
{
    for (a = 0; nb > 0 && nb < 1; a++) {
        nb = nb * 10;
    }
    my_put_nbr_fe(nb);
    my_putchar('e');
    my_putchar('-');
    my_put_nbr(0);
    my_put_nbr(a);
}

double exp_two(double nb, int b)
{
    for (b = 0; nb >= 10; b++) {
        nb = nb / 10;
    }
    my_put_nbr_f(nb);
    my_putchar('e');
    my_putchar('+');
    if (b > 0 && b < 10) {
        my_put_nbr(0);
    }
    my_put_nbr(b);
}

double my_put_nbr_e(double nb)
{
    int a = 0;
    int b = 0;

    if (nb == 0.0) {
        my_putstr("0.000000e+00");
    }
    if (nb > 1 && nb <= 9) {
        my_put_nbr_f(nb);
        my_putstr("e+00");
    }
    if (nb > 0 && nb < 1) {
        exp_one(nb, a);
    }
    if (nb > 9) {
        exp_two(nb, b);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_e(-1 * nb);
    }
}
