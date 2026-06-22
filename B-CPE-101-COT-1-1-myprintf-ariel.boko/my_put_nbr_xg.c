/*
** EPITECH PROJECT, 2024
** my_put_nbr_X
** File description:
** Convert from decimal to hexadecimal
*/

#include <unistd.h>
#include "include/my.h"
#include <stdio.h>

unsigned int my_put_nbr_xg(unsigned int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    }
    if (nb >= 10 && nb <= 15) {
        my_putchar(nb + 55);
    }
    if (nb > 15) {
        my_put_nbr_xg(nb / 16);
        my_put_nbr_xg(nb % 16);
    }
    return 0;
}
