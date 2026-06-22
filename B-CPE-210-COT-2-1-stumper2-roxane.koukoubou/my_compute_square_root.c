/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** TASK 05
*/

#include <stdio.h>

int square_root(int nb)
{
    int sqrt = 0;

    if (nb < 0) {
    return 0;
    }
    while (sqrt <= (nb / 2)) {
    sqrt++;
    if (sqrt * sqrt == nb) {
    return sqrt;
    }
    }
    return 0;
}
