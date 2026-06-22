/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** activate_emergency_protocols
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/pipeto.h"

char *hash(char *str)
{
    str = strdup(str);
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i] + i - strlen(str);
    return str;
}

void activate_emergency_protocols(void)
{
    char input[100];
    char *password = getenv("EMERGENCY_PASSWD");

    if (password == NULL || !password)
        return;
    printf("Enter emergency password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) == 0) {
        printf("No password entered, emergency");
        printf(" protocols not activated.\n");
        return;
    }
    if (strcmp(hash(input), hash(password)) == 0) {
        printf("{Emergency protocols activated, you are now admin !}\n");
        IS_ADMIN = true;
    }
    return;
}
