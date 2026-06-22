/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** run_diagnostic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/pipeto.h"
#include <stdbool.h>
#include <unistd.h>

void cut_run_diagnostic(void)
{
    printf("Performing system health check...\n");
    sleep(1);
    printf("System health: OK\n");
    printf("Diagnostic complete.\n");
}

void cut_debug(char *sensitive_info)
{
    if (IS_ADMIN == true)
        printf("Diagnostic result: %s\n", sensitive_info);
    else
        printf("Permission denied...\n");
}

void print_running(char *input)
{
    input[strcspn(input, "\n")] = '\0';
    printf("Running diagnostic...\n");
    sleep(1);
}

void run_diagnostic(void)
{
    char input[32];
    int diagnostic_code = 0;
    const char sensitive_info[25] = "{SECRET DIAGNOSTIC KEY}";

    printf("Enter diagnostic mode (normal/debug/advanced): ");
    fgets(input, sizeof(input), stdin);
    print_running(input);
    if (strcmp(input, "debug") == 0) {
        printf("Debug mode activated.\n");
        cut_debug(sensitive_info);
    } else if (strcmp(input, "advanced") == 0) {
        diagnostic_code = rand() % 1000;
        printf("Diagnostic result: Code %d\n", diagnostic_code);
    } else if (strcmp(input, "normal") == 0) {
        printf("Diagnostic result: Standard check passed.\n");
    } else {
        printf("Error: Unknown diagnostic mode.\n");
        return;
    }
    cut_run_diagnostic();
}
