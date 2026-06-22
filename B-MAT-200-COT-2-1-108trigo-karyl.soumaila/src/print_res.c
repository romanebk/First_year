/*
** EPITECH PROJECT, 2025
** function
** File description:
** just print the result
*/

#include "../include/my.h"

void print_matrix(double **mat, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%.2f%c", mat[i][j], (j != size - 1) ? '\t' : '\n');
    }
}
