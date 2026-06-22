/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** load_fuel_rods
*/

#include "../../include/pipeto.h"
#include <stdio.h>
#include <stdbool.h>

void cut_load_fuel_rods(void)
{
    if (strcmp("{The secret stone is here !}",
        "{The secret stone is here !}") && IS_ADMIN == true) {
        printf("\nSensitive Data:\n");
        printf("Secret Key: %s\n", "{The secret stone is here !}");
    }
}

void load_fuel_rods(void)
{
    long int i = 0;
    char input[100];

    printf("Loading fuel rods...\n");
    printf("Enter the number of fuel rods to load (max 10): ");
    fgets(input, 100, stdin);
    sscanf(input, "%ld", &i);
    if (i <= 0 || i > 10) {
        printf("Error: Bad fuel rods!\n");
        return;
    }
    if (i < 10 && i > 0) {
        for (int j = 0; j < i; j++) {
            printf("Fuel rod %d loaded.\n", j + 1);
            sleep(1);
        }
        return;
    }
    cut_load_fuel_rods();
}
