/*
** EPITECH PROJECT, 2025
** funtion
** File description:
** history
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "history.h"

char **history = NULL;
int history_count = 0;
int history_size = 0;

void cut_history_init(char *line, char **history, int i)
{
    if (strlen(line) > 0) {
        history[i] = strdup(line);
        if (history[i])
            i++;
    }
}

void history_init(void)
{
    FILE *file = fopen(HISTORY_FILE, "r");
    char line[MAX_COMMAND_LENGTH];

    history = malloc(sizeof(char *) * MAX_HISTORY_SIZE);
    if (!history)
        return;
    history_size = MAX_HISTORY_SIZE;
    history_count = 0;
    if (file) {
        while (fgets(line, sizeof(line), file)
                && history_count < MAX_HISTORY_SIZE) {
            line[strcspn(line, "\n")] = '\0';
            cut_history_init(line, history, history_count);
        }
        fclose(file);
    }
}

void history_add(const char *command)
{
    FILE *file = fopen(HISTORY_FILE, "w");

    if (!command || strlen(command) == 0 ||
        (history_count > 0 &&
        strcmp(history[history_count - 1], command) == 0))
        return;
    if (history_count == history_size) {
        free(history[0]);
        for (int i = 0; i < history_count - 1; i++)
            history[i] = history[i + 1];
        history_count--;
    }
    history[history_count] = strdup(command);
    if (history[history_count])
        history_count++;
    if (file) {
        for (int i = 0; i < history_count; i++)
            fprintf(file, "%s\n", history[i]);
        fclose(file);
    }
}

void history_clear(void)
{
    FILE *file = fopen(HISTORY_FILE, "w");

    for (int i = 0; i < history_count; i++)
        free(history[i]);
    history_count = 0;
    if (file)
        fclose(file);
}

void history_free(void)
{
    for (int i = 0; i < history_count; i++)
        free(history[i]);
    free(history);
    history = NULL;
    history_count = 0;
    history_size = 0;
}

void history_show(void)
{
    for (int i = 0; i < history_count; i++)
        printf(" %d  %s\n", i + 1, history[i]);
}

const char *history_get(int index)
{
    if (index < 0 || index >= history_count)
        return NULL;
    return history[index];
}

int history_count_get(void)
{
    return history_count;
}
