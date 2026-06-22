/*
** EPITECH PROJECT, 2025
** derivate
** File description:
** derivate
*/

#include "../include/my.h"

double *derivate(double *tab, double *arr, int rows)
{
    double *final = malloc(sizeof(double) * rows);

    for (int i = 1; i < rows - 1; i++) {
        double first = (arr[i] - arr[i - 1]);
        double second = (arr[i + 1] - arr[i]);
        if (second == 0 || first == 0)
            exit(0);
        double ph_first = (tab[i + 1] - tab[i]) / second;
        double ph_second = (tab[i] - tab[i - 1]) / first;
        double total = first + second;
        final[i] = (second * ph_second + first * ph_first) / total;
    }
    return final;
}

double find_max(double *arr, double *dev, int len)
{
    double max = dev[1];
    int j = 1;
    int i = 0;

    for (; j < len - 1; j++) {
        if (dev[j] > max) {
            max = dev[j];
            i = j;
        }	
    }
    return arr[i];
}
