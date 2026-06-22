/*
** EPITECH PROJECT, 2025
** parse
** File description:
** me
*/

#include "../include/my.h"

char **parsing(char *line, const char *sep)
{
    int max = 1000;
    char **args = malloc(sizeof(char *) * (max + 1));
    int count = 0;
    char *tab;

    if (!args)
        return NULL;
    tab  = strtok(line, sep);
    while (tab) {
        if (check_arg(tab) == 1)
            exit(84);
        args[count] = tab;
        count++;
        if (count >= max)
            break;
        tab = strtok(NULL, sep);
    }
    if (count % 2 != 0)
        exit(84);
    args[count] = NULL;
    return args;
}

double *range_volume(char **tab, int *rows)
{
    int j = 0;
    double *arr = malloc(sizeof(double));

    for (int i = 0; tab[i] != NULL; i++) {
        if ((i % 2) == 0) {
            arr[j] = atof(tab[i]);
            j++;
            arr = realloc(arr, sizeof(double) * (j + 2));
        }
    }
    *rows = j;
    return arr;
}

double *range_ph(char **tab, int *rows)
{
    int size = 0;
    int j = 0;
    for (size = 0; tab[size] != NULL; size++);
    double *arr = malloc(sizeof(double) * size);

    for (int i = 1; tab[i] != NULL; i++) {
        if ((i % 2) != 0) {
            if (atof(tab[i]) < 0  || atof(tab[i]) > 14)
                exit(0);
            arr[j] = atof(tab[i]);
            j++;
        }
    }
    arr[j] = 0;
    *rows = j;
    return arr;
}
