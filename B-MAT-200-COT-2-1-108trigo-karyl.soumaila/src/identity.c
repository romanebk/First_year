/*
** EPITECH PROJECT, 2025
** function
** File description:
** create a identity matrix
*/

#include "../include/my.h"

double **identity_matrix(int size)
{
    double **mat = allocate_matrix(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mat[i][j] = (i == j) ? 1 : 0;
    return mat;
}
