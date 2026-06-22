/*
** EPITECH PROJECT, 2024
** my_put_nbr_base_u.c
** File description:
** Displaying the unsigned number
*/

#include <unistd.h>
#include "include/my.h"
#include <stdio.h>

unsigned int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-1 * nb);
    } else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return 0;
}
