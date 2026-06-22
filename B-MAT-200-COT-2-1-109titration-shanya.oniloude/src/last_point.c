/*
** EPITECH PROJECT, 2025
** 
** File description:
** 
*/

#include "../include/my.h"

double last_point(double *arr, double *estimate, int r)
{
    int i = 1;
    int j = 0;

    for (; i < r; i++) {
        if (estimate[i - 1] > 0 && estimate[i] < 0) {
            j = i;
        }
        
    }
    return arr[j];
}
