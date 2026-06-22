/*
** EPITECH PROJECT, 2025
** usage.c
** File description:
** usage.c
*/

#include "../include/my.h"

int usage(int ac, char *av[])
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("Usage: ./%s [-r] [-t] str", av[1]);
        printf("[SEARCHED_CHARACTERS]\n-r if set, group the ");
        printf("characters having the same number of ");
        printf("occurences (see examples).\n-t if set, ");
        printf("characters have to be sorted by number ");
        printf("of occurences (highest to lowest).\n");
        printf("SEARCHED CHARACTERS: if a second strings is ");
        printf("passed as parameters, count the occurences of ");
        printf("characters in the STR but only for those ");
        printf("present in SEARCHED_CHARACTERS\n");
        exit(0);
    }
}
