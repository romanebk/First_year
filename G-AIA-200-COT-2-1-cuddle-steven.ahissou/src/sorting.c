/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Sorting
*/

#include "../include/dataframe.h"

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    return NULL;
}

bool sort_func(void *value1, void *value2)
{
    return *(int *) value1 > *(int *) value2;
}
