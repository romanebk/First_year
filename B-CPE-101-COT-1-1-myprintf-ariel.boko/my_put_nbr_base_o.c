/*
** EPITECH PROJECT, 2024
** my_put_nbr_base
** File description:
** Converting to octal base
*/

#include <unistd.h>
#include <stdio.h>
#include "include/my.h"

int my_put_nbr_base_o(unsigned int nb)
{
    if (nb >= 0 && nb <= 7) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr_base_o(nb / 8);
        my_put_nbr_base_o(nb % 8);
    }
    return nb;
}
