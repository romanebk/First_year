/*
** EPITECH PROJECT, 2025
** main
** File description:
** main function
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 1)
        create();
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        usage(ac, av);
    else
        return 84;
}
