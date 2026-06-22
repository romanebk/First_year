/*
** EPITECH PROJECT, 2025
** function
** File description:
** copy the matrix
*/

#include "../include/my.h"

double **copy_matrix(double **mat, int size)
{
    double **copy = allocate_matrix(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            copy[i][j] = mat[i][j];
    return copy;
}
