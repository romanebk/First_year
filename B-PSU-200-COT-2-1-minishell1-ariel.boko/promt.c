/*
** EPITECH PROJECT, 2025
** ghjk
** File description:
** hgvfcxw
*/

#include "my.h"

int cut_prompt(char *buffer)
{
    if (buffer == NULL)
        return 1;
    return 0;
}

int prompt(char **argv, char **env)
{
    char *buf = NULL;
    char *input = NULL;
    size_t len = 0;

    while (1) {
        buf = getcwd(buf, 100);
        cut_prompt(buf);
        mini_printf(GREEN "[my_shell]" COLOR " " BLUE);
        mini_printf("%s" COLOR "$> ", buf);
        if (getline(&input, &len, stdin) == -1) {
            free(input);
            free(buf);
            break;
        } else
            execute_command(input, env);
    }
    free(input);
    free(buf);
    return 0;
}
