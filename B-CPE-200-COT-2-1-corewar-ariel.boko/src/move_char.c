/*
** EPITECH PROJECT, 2025
** function
** File description:
** move a char
*/

#include "../include/my.h"

long long get_basic_value(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (c == base[i])
            return (i);
    }
    return (0);
}

long long put_base_ten(char *nbr, char *base_from)
{
    long long calcul = 0;
    long long pow = 1;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        calcul += get_basic_value(nbr[i], base_from) * pow;
        pow *= my_strlen(base_from);
    }
    return (calcul);
}
