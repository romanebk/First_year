/*
** EPITECH PROJECT, 2025
** function
** File description:
** print the usage mode
*/

#include "../include/my.h"

int usage(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0') {
        printf("USAGE\n\t./108trigo fun a0 a1 a2 ...\n\n");
        printf("DESCRIPTION\n\tfun\tfunction to be applied,");
        printf(" among at least “EXP”, “COS”, “SIN”, “COSH”\n");
        printf("\t\tand “SINH”\n");
        printf("\tai\tcoeficients of the matrix\n");
    } else
        exit(84);
    return 0;
}
