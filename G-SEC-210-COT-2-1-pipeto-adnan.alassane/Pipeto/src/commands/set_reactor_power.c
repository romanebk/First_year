/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** set_reactor_power
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

int new_power = 0;

void printf_reactor(void)
{
    printf("\nReactor power adjustment may be incorrect.\n");
    printf("Reactor systems are behaving erratically!\n");
    printf("Reactor core temperature rising uncontrollably...\n");
    printf("{12EXPLOSION34}\n");
    printf("Emergency shutdown initiated!\n\n");
    exit(1);
}

void cut_end_reactor(int new_power)
{
    if (new_power < 0) {
        printf("Reactor power set to an invalid value: %d\n", new_power);
        printf("Reactor core meltdown imminent!\n");
    } else {
        printf("Reactor power set to: %d\n", new_power);
        printf("Reactor operating within safe parameters.\n");
    }
}

void set_reactor_power(void)
{
    char *endptr = NULL;
    char power[11];
    long input_power = 0;

    printf("Enter reactor power level: ");
    if (fgets(power, sizeof(power), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    power[strcspn(power, "\n")] = '\0';
    errno = 0;
    input_power = strtol(power, &endptr, 10);
    if (errno != 0 || *endptr != '\0') {
        printf("Invalid input: Please enter a valid number.\n");
        return;
    }
    if (input_power > INT_MAX - 1000)
        printf_reactor();
    new_power = (int)input_power + 1000;
    cut_end_reactor(new_power);
}
