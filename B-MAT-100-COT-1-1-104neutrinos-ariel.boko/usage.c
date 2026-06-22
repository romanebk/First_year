/*
** EPITECH PROJECT, 2024
** usage
** File description:
** usage
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int usage(int argc, char **argv)
{
    if (argc != 5 && argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        printf("USAGE\n");
        printf("    ./104neutrinos n a h sd\n\n\n");
        printf("DESCRIPTION\n");
        printf("    n      number of values\n");
        printf("    a      arithmetic mean\n");
        printf("    h      harmonic mean\n");
        printf("    sd     standard deviation\n");
    } else {
        exit(84);
    }
    return 0;
}
