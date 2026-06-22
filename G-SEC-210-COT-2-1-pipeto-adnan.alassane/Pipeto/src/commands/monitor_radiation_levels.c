/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** monitor_radiation_levels
*/

#include <stdio.h>
#include <string.h>


void secret_function(void)
{
    printf("{The stone isn't in the pocket anymore ...}\n");
}

void monitor_radiation_levels(void)
{
    char buffer[100];
    int level = 0;
    void (*function_ptr)(void) = NULL;

    printf("Enter radiation levels: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input\n");
        return;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    printf("Radiation Levels: %s\n", buffer);
    if (function_ptr)
        function_ptr();
    else
        printf("Function Pointer: %p\n", (void *)function_ptr);
}
