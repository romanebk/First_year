/*
** EPITECH PROJECT, 2025
** BOO
** File description:
** BOO
*/

#ifndef BOO_H
    #define BOO_H
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <math.h>
    #include <stdbool.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

dataframe_t *read1(const char *filename, const char *separator);
dataframe_t *df_create(int nb_row, int nb_col);
void df_free(dataframe_t *var);
dataframe_t *stock_data(const char *filename);
int uns_integer(char *str);
int is_integer(char *str);
int is_float(char *str);
int is_bool(char *str);
dataframe_t *df_read_csv(const char *filename, const char *separator);
void process_line(const char *line, const char *separator);
int df_write_csv(dataframe_t *df, const char *filename);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
bool filter_func(void *value);
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2));
bool sort_func(void *value1, void *value2);
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values));
void *agg_func(void **values, int nb_values);
dataframe_t *df_apply(dataframe_t *dataframe,
    const char *column, void *(*apply_func)(void *value));
void *apply_func(void *value);
dataframe_t *df_to_type(dataframe_t *dataframe,
    const char *column, column_type_t downcast);
void *apply_func(void *value);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);

#endif
