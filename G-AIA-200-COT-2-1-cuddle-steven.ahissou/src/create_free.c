/*
** EPITECH PROJECT, 2025
** function
** File description:
** create and free
*/

#include "../include/dataframe.h"

dataframe_t *df_create(int nb_row, int nb_col) 
{
    dataframe_t *var = malloc(sizeof(dataframe_t));

    var->nb_rows = nb_row;
    var->nb_columns = nb_col;
    var->column_names = malloc(sizeof(char *) * nb_col);
    var->column_types = malloc(nb_col * sizeof(column_type_t));
    var->data = malloc(nb_row * sizeof(void **));
    for (int i = 0; i < nb_row; i++)
        var->data[i] = malloc(nb_col * sizeof(void *));
    return var;
}

void df_free(dataframe_t *var)
{
    for (int i = 0; i < var->nb_rows; i++) {
        for (int j = 0; j < var->nb_columns; j++)
            free(var->data[i][j]);
        free(var->data[i]);
    }
    free(var->data);
    for (int i = 0; i < var->nb_columns; i++)
        free(var->column_names[i]);
    free(var->column_names);
    free(var->column_types);
    free(var);
}
