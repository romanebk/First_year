/*
** EPITECH PROJECT, 2025
** BOO
** File description:
** BOO
*/

#include "../include/dataframe.h"

void process_line(const char *line, const char *separator)
{
    int size = 256;
    char *token = (char *) malloc(size);
    char *line_copy = strdup(line);

    token = strtok(line_copy, separator);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, separator);
    }
    free(line_copy);
    free(token);
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *opn = fopen(filename, "r");
    int size = 256;
    char *buffer = (char *) malloc(size);
    char *line = NULL;

    if (opn) {
        while (1) {
            line = fgets(buffer, size, opn);
            if (line == NULL)
                break;
            process_line(line, separator);
        }
        free(buffer);
        fclose(opn);
        return 0;
    } else
        return NULL;
}
