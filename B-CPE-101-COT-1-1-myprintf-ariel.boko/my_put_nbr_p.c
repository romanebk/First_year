/*
** EPITECH PROJECT, 2024
** my_put_nbr_p.c
** File description:
** my_put_nbr_p.c
*/

#include <unistd.h>
#include "include/my.h"
#include <stdio.h>
#include <stdarg.h>

unsigned long my_put_nbr_p(unsigned long nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    }
    if (nb >= 10 && nb <= 15) {
        my_putchar((nb + 55) + 32);
    }
    if (nb > 15) {
        my_put_nbr_p(nb / 16);
        my_put_nbr_p(nb % 16);
    }
    return 0;
}
