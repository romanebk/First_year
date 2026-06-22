/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Filtering
*/

#include "../include/dataframe.h"

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value))
{
    return NULL;
}

bool filter_func(void *value)
{
    return *(int *) value > 30;
}
