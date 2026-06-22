/*
** EPITECH PROJECT, 2024
** usage
** File description:
** usage
*/

#include "../include/my.h"

int usage(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        printf("USAGE\n");
        printf("    ./106bombyx n [k | i0 i1]\n");
        printf("DESCRIPTION\n");
        printf("    n       number of first generation individuals\n");
        printf("    k       growth rate from 1 to 4\n");
        printf("    i0      initial generation (included)\n");
        printf("    i1      final generation (included)\n");
    } else {
        return 84;
    }
    return 0;
}
