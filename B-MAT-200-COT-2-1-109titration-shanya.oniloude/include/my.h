/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_H
   #define MY_H

int check_arg(char *str);
int usage(int argc, char **argv);
char *open_file(char const *filepath);
char **parsing(char *line, const char *sep);
double *range_volume(char **tab, int *rows);
double *range_ph(char **tab, int *rows);
double *derivate(double *tab, double *arr, int rows);
double find_max(double *arr, double *dev, int len);
void interpolate_second_derivative(double *arr, double *second_derivative, int r, double equi_point);
double last_point(double *arr, double *estimate, int r);
#endif
