/*
** EPITECH PROJECT, 2025
** function
** File description:
** function trigonométrique
*/

#include "../include/my.h"

double **exp_matrix(double **mat, int size)
{
    double **result = identity_matrix(size);
    double **pow_mat;
    double **div_mat;
    double **temp;

    for (int i = 1; i < 50; i++) {
        pow_mat = power_matrix(mat, size, i);
        div_mat = divide_matrix(pow_mat, size, tgamma(i + 1));
        temp = add_matrices(result, div_mat, size);
        free_matrix(result, size);
        free_matrix(div_mat, size);
        result = temp;
    }
    return result;
}

double **cos_matrix(double **mat, int size)
{
    double **result = identity_matrix(size);
    double **pow_mat;
    double **div_mat;
    double **temp;

    for (int i = 1; i < 40; i++) {
        pow_mat = power_matrix(mat, size, 2 * i);
        div_mat = divide_matrix(pow_mat, size, tgamma(2 * i + 1));
        temp = (i % 2 == 0) ? add_matrices(result, div_mat, size)
            : sub_matrices(result, div_mat, size);
        free_matrix(result, size);
        free_matrix(div_mat, size);
        result = temp;
    }
    return result;
}

double **sin_matrix(double **mat, int size)
{
    double **result = copy_matrix(mat, size);
    double **pow_mat;
    double **div_mat;
    double **temp;

    for (int i = 1; i < 40; i++) {
        pow_mat = power_matrix(mat, size, 2 * i + 1);
        div_mat = divide_matrix(pow_mat, size, tgamma(2 * i + 2));
        temp = (i % 2 == 0) ? add_matrices(result, div_mat, size)
            : sub_matrices(result, div_mat, size);
        free_matrix(result, size);
        free_matrix(div_mat, size);
        result = temp;
    }
    return result;
}

double **cosh_matrix(double **mat, int size)
{
    double **result = identity_matrix(size);
    double **pow_mat;
    double **div_mat;
    double **temp;

    for (int i = 1; i < 40; i++) {
        pow_mat = power_matrix(mat, size, 2 * i);
        div_mat = divide_matrix(pow_mat, size, tgamma(2 * i + 1));
        temp = add_matrices(result, div_mat, size);
        free_matrix(result, size);
        free_matrix(div_mat, size);
        result = temp;
    }
    return result;
}

double **sinh_matrix(double **mat, int size)
{
    double **result = copy_matrix(mat, size);
    double **pow_mat;
    double **div_mat;
    double **temp;

    for (int i = 1; i < 40; i++) {
        pow_mat = power_matrix(mat, size, 2 * i + 1);
        div_mat = divide_matrix(pow_mat, size, tgamma(2 * i + 2));
        temp = add_matrices(result, div_mat, size);
        free_matrix(result, size);
        free_matrix(div_mat, size);
        result = temp;
    }
    return result;
}
