/*
** EPITECH PROJECT, 2025
** function
** File description:
** history.h
*/

#ifndef HISTORY_H
    #define HISTORY_H
    #define HISTORY_FILE ".pipeto_history"
    #define MAX_HISTORY_SIZE 1000
    #define MAX_COMMAND_LENGTH 256

void history_init(void);
void history_add(const char *command);
void history_clear(void);
void history_free(void);
void history_show(void);
const char *history_get(int index);
int history_count_get(void);

#endif /* HISTORY_H */
