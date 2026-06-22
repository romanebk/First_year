/*
** EPITECH PROJECT, 2025
** function
** File description:
** sub, add and multiply matrix
*/

#include "../include/my.h"

double **multiply_matrices(double **mat1, double **mat2, int size)
{
    double **result = allocate_matrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return result;
}

double **power_matrix(double **mat, int size, int exp)
{
    double **result = copy_matrix(mat, size);
    double **temp;

    for (int i = 1; i < exp; i++) {
        temp = multiply_matrices(result, mat, size);
        free_matrix(result, size);
        result = temp;
    }
    return result;
}

double **divide_matrix(double **mat, int size, double k)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mat[i][j] /= k;
    return mat;
}

double **add_matrices(double **mat1, double **mat2, int size)
{
    double **result = allocate_matrix(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
    return result;
}

double **sub_matrices(double **mat1, double **mat2, int size)
{
    double **result = allocate_matrix(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];
    return result;
}
