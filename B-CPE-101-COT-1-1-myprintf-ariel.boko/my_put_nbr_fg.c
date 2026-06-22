/*
** EPITECH PROJECT, 2024
** my_put_nbr_fg
** File description:
** Displaying decimal numbers
*/

#include <stdio.h>
#include "include/my.h"

int fg_one(double decimal_part, int compt)
{
    for (compt = 0; decimal_part < 100000; compt++) {
        my_put_nbr(0);
        decimal_part = decimal_part * 10;
    }
    for (; compt > 0; compt--) {
        decimal_part = decimal_part / 10;
    }
}

int my_put_nbr_fg(double nb)
{
    int whole_part = nb;
    double a = nb - whole_part;
    double decimal_part;
    int compt = 0;

    if (nb > 0) {
        my_put_nbr(whole_part);
        my_putchar('.');
        decimal_part = (a * 1000000 + 0.5);
        fg_one(decimal_part, compt);
        decimal_part = decimal_part;
        my_put_nbr(decimal_part);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_f(-1 * nb);
    }
}
