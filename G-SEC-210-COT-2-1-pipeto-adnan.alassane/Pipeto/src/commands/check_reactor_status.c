/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** check_reactor_status
*/

#include <stdio.h>
#include <unistd.h>

static void cut_encrypt_message(const char *input,
    char *output, int shift, int *i)
{
    if (input[*i] >= 'A' && input[*i] <= 'Z')
        output[*i] = ((input[*i] - 'A' + shift) % 26) + 'A';
    else if (input[*i] >= 'a' && input[*i] <= 'z')
        output[*i] = ((input[*i] - 'a' + shift) % 26) + 'a';
    else
        output[*i] = input[*i];
}

void encrypt_message(const char *input, char *output, int shift)
{
    for (int i = 0; input[i] != '\0'; i++)
        cut_encrypt_message(input, output, shift, &i);
}

void check_reactor_status(void)
{
    const char *message = "ReactorStatusOK";
    char encrypted_message[50] = {0};

    printf("Starting reactor status check...\n");
    sleep(1);
    printf("Checking core temperature...\n");
    sleep(1);
    printf("Core temperature: Normal\n");
    sleep(1);
    printf("Checking coolant flow rate...\n");
    sleep(1);
    printf("Coolant flow rate: Stable\n");
    sleep(1);
    printf("Checking radiation levels...\n");
    sleep(2);
    printf("Radiation levels: Safe\n\nEncrypting critical reactor data...\n");
    encrypt_message(message, encrypted_message, 3);
    sleep(1);
    printf("Reactor status: OK\nReactor status check complete.\n\n");
}
