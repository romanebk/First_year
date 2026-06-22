/*
** EPITECH PROJECT, 2025
** function
** File description:
** allocate and free memories
*/

#include "../include/my.h"

double **allocate_matrix(int size)
{
    double **matrix = malloc(size * sizeof(double *));

    if (!matrix)
        return NULL;
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(double));
        if (!matrix[i])
            return NULL;
    }
    return matrix;
}

void free_matrix(double **matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}
