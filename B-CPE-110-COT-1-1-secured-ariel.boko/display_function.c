/*
** EPITECH PROJECT, 2025
** f"rfe"
** File description:
** ecfaedf
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "hashtable.h"

void my_char(char c)
{
    write(1, &c, 1);
}

int my_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_char(str[i]);
        i++;
    }
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb >= 0 && nb < 10) {
        my_char(48 + nb);
    }
    if (nb < 0) {
        my_char('-');
        my_put_nbr((nb) * (-1));
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return nb;
}
