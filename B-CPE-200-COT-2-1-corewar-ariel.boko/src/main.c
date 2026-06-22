/*
** EPITECH PROJECT, 2025
** main
** File description:
** main.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/my.h"

int cut_main(int ac, char **av)
{
    vm_t *vm;
    int exit_code = 0;

    vm = init_vm();
    if (vm == NULL)
        return 84;
    if (parse_args(ac, av, vm) != 0) {
        destroy_vm(vm);
        return 84;
    }
    if (vm->nb_players <= 1 || vm->nb_players > 4)
        return 84;
    init_display();
    exit_code = run_vm(vm);
    endwin();
    destroy_vm(vm);
    return exit_code;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' &&
        av[1][1] == 'h' && av[1][2] == '\0') {
        usage(ac, av);
        return 0;
    } else if (ac > 1)
        return cut_main(ac, av);
    else
        return 84;
    return 0;
}
