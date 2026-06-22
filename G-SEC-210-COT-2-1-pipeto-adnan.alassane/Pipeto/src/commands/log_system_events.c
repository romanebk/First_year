/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** log_system_events
*/

#include "../../include/pipeto.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void log_system_event(void)
{
    FILE *log = NULL;
    char input[100];
    const char secret_key[32] = "{SECRET_LOG_12PIERRE34}";

    printf("Enter command: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error: failed to read input.\n");
        return;
    }
    input[strcspn(input, "\n")] = '\0';
    log = fopen("Data/system.log", "a");
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    printf("Logging event: %s\n", input);
    fprintf(log, "EVENT: %s\n", input);
    if (strstr(input, "leak") && IS_ADMIN == true)
        fprintf(log, "SECRET_KEY_LEAKED: %s\n", secret_key);
    fclose(log);
}
