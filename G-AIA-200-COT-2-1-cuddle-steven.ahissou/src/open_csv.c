/*
** EPITECH PROJECT, 2025
** function
** File description:
** function
*/

#include "../include/dataframe.h"

dataframe_t *read1(const char *filename, const char *separator)
{
    FILE* file = fopen(filename, "r");
    char line[1024];
    char *token = NULL;
    int nb_col = 0;
    int i = 0;
    int a = 0;
    int nb_row = 0;
    dataframe_t *var;

    if (!file)
        return NULL;
    for (; fgets(line, sizeof(line), file); i++) {
        token = strtok(line, separator);
        for (; token != NULL; a++) {
            token = strtok(NULL, separator);
        }
    }
    var = df_create(i - 1, a / i);
    fclose(file);
    return var;
}

dataframe_t *fill(const char *filename)
{
    FILE* file = fopen(filename, "r");
    char line[1024];
    char *token = NULL;
    dataframe_t *var = read1(filename, ", \n");

    if (!file)
        return NULL;
    fgets(line, sizeof(line), file);
    line[strcspn(line, "\n")] = 0;
    token = strtok(line, ", ");
    for (int i = 0; i < var->nb_columns; i++) {
        var->column_names[i] = strdup(token);
        token = strtok(NULL, ", ");
    }
    fclose(file);
    return var;
}

dataframe_t *col_typ(const char *filename)
{
    FILE* file = fopen(filename, "r");
    char line[1024];
    char *token = NULL;
    int i = 0;
    dataframe_t *var = fill(filename);

    if (!file)
        return NULL;
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);
    line[strcspn(line, "\n")] = 0;
    token = strtok(line, ", ");
    for (; token != NULL && i < var->nb_columns; i++) {
        if (uns_integer(token) == 1)
            var->column_types[i] = UNDEFINED;
        else if (is_integer(token) == 1)
            var->column_types[i] = INT;
        else if (is_float(token) == 1)
            var->column_types[i] = FLOAT;
        else if (is_bool(token) == 1)
            var->column_types[i] = BOOL;
        else
            var->column_types[i] = STRING;
        token = strtok(NULL, ", ");
    }
    fclose(file);
    return var;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE* file = fopen(filename, "r");
    char line[1024];
    char *token = NULL;
    int i = 0;
    dataframe_t *var = col_typ(filename);

    if (!file)
        return NULL;
    fgets(line, sizeof(line), file);
    token = strtok(line, ", ");
    for (int i = 0; i < var->nb_rows; i++) {
        fgets(line, sizeof(line), file);
        token = strtok(line, " \n");
        for (int j = 0; j < var->nb_columns; j++) {
            var->data[i][j] = strdup(token);
            token = strtok(NULL, ", ");
        }
    }
    fclose(file);
    return var;
}
