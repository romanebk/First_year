/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/

#include "my.h"

int usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        mini_printf("USAGE\n\tmy_world\n\nDESCRIPTION\n");
        my_putstr("\tGenerates a 3-dimensional virtual world\n");
    } else {
        return 84;
    }
}
