/*
** EPITECH PROJECT, 2025
** function
** File description:
** principale function
*/

#include "../include/my.h"

int rappel(int argc, char **argv)
{
    int size = (int) sqrt(argc - 2);
    double **result;
    double **matrix = allocate_matrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            matrix[i][j] = strtod(argv[2 + i * size + j], NULL);
    }
    if (!strcmp(argv[1], "EXP"))
        result = exp_matrix(matrix, size);
    else if (!strcmp(argv[1], "COS"))
        result = cos_matrix(matrix, size);
    else if (!strcmp(argv[1], "SIN"))
        result = sin_matrix(matrix, size);
    else if (!strcmp(argv[1], "COSH"))
        result = cosh_matrix(matrix, size);
    else if (!strcmp(argv[1], "SINH"))
        result = sinh_matrix(matrix, size);
    print_matrix(result, size);
    free_matrix(matrix, size);
    free_matrix(result, size);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' &&
        argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
        return 0;
    }
    if (argc < 3 || valid_coe(argc) == 84 || check_input(argc, argv) == 84)
        exit(84);
    error_case(argc, argv);
    rappel(argc, argv);
    return 0;
}
