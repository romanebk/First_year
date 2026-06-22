/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** simulate_meltdown
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void cut_simulate_meltdown(int random_number,
    char reactor_status[32], char secret_code[16])
{
    printf("Generated random number: %d\n", random_number);
    if (random_number < 5) {
        printf("Meltdown simulated! Reactor core is overheating.\n");
        strcpy(reactor_status, "Reactor Overheating");
        printf("Critical Error: Secret Code Leaked: %s\n", secret_code);
        printf("Reactor core temperature: %d\n", random_number);
        printf("Reactor core status: %s\n", reactor_status);
        return;
    }
}

void cut_condition(int random_number, char reactor_status[32])
{
    if (random_number < 10) {
        printf("Meltdown simulated! Reactor core is overheating.\n");
        strcpy(reactor_status, "Reactor Overheating");
        return;
    }
}

void simulate_meltdown(void)
{
    char reactor_status[32] = "Reactor Stable";
    int random_number = 0;
    char secret_code[16] = "{MELTDOWN1234}";

    srand((unsigned int)time(NULL));
    random_number = rand() % 100;
    cut_simulate_meltdown(random_number, reactor_status, secret_code);
    cut_condition(random_number, reactor_status);
    if (random_number < 20) {
        printf("Warning: Reactor core temperature rising.\n");
        strcpy(reactor_status, "Reactor Warning");
    } else if (random_number < 50) {
        printf("Alert: Reactor core temperature stable.\n");
        strcpy(reactor_status, "Reactor Stable");
    } else {
        printf("Reactor core temperature normal.\n");
        strcpy(reactor_status, "Reactor Normal");
    }
    printf("Reactor core temperature: %d\n", random_number);
    printf("Reactor core status: %s\n", reactor_status);
}
