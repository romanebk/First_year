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
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        printf("USAGE\n");
        printf("    ./105demography [code]+\n\n");
        printf("DESCRIPTION\n");
        printf("    code    country code\n");
    } else {
        exit(84);
    }
    return 0;
}
