/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Aggre
*/

#include "../include/dataframe.h"

dataframe_t *df_apply(dataframe_t *dataframe,
    const char *column, void *(*apply_func)(void *value))
{
    return NULL;
}

void *agg_func(void **values, int nb_values)
{
    int *sum = malloc(sizeof(int));

    *sum = 0;
    for (int i = 0; i < nb_values; i++)
        *sum += *(int *) values[i];
    return sum;
}
