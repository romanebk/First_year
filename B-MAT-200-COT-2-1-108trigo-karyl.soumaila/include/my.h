/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#ifndef MY_H
    #define MY_H

int usage(int argc, char **argv);
int valid_coe(int ac);
int check_input(int ac, char **av);
int check_arg(char *str);
int error_case(int ac, char **av);
double **identity_matrix(int size);
int rappel(int argc, char **argv);
int main(int argc, char **argv);
void print_matrix(double **mat, int size);
double **copy_matrix(double **mat, int size);
double **multiply_matrices(double **mat1, double **mat2, int size);
double **power_matrix(double **mat, int size, int exp);
double **divide_matrix(double **mat, int size, double k);
double **add_matrices(double **mat1, double **mat2, int size);
double **sub_matrices(double **mat1, double **mat2, int size);
double **exp_matrix(double **mat, int size);
double **cos_matrix(double **mat, int size);
double **sin_matrix(double **mat, int size);
double **cosh_matrix(double **mat, int size);
double **sinh_matrix(double **mat, int size);
double **allocate_matrix(int size);
void free_matrix(double **matrix, int size);

#endif
