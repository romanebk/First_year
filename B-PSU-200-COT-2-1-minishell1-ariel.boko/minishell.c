/*
** EPITECH PROJECT, 2025
** fghjkl
** File description:
** dfghj
*/

#include "my.h"

int cut_execute_command(char *input, char **args, char **env)
{
    if (args[0] == NULL)
        return 0;
    if (my_strcmp(args[0], "exit") == 0) {
        my_putstr_error("exit\n");
        exit(0);
    }
    if (my_strcmp(args[0], "setenv") == 0 ||
        my_strcmp(args[0], "unsetenv") == 0)
        return 0;
    if (my_strcmp(args[0], "env") == 0) {
        print_env(env);
        return 0;
    } else if (my_strcmp(args[0], "cd") == 0) {
        recode_cd(env, input, args);
        return 0;
    }
    my_execve(input, env, args);
    return 0;
}

int count(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';')
            a++;
    }
    return a;
}

char **stock_command1(char *input, char **env)
{
    char *token = NULL;
    int i = 0;
    char **command = NULL;

    command = malloc(sizeof(char *) * (count(input) + 2));
    token = strtok(input, ";");
    if (!token || !command)
        return NULL;
    for (; token != NULL; i++) {
        command[i] = my_strdup(token);
        token = strtok(NULL, ";");
    }
    command[i] = NULL;
    return command;
}

int execute_command(char *input, char **env)
{
    int i = 0;
    int j = 0;
    char *args[1024];
    char *token = NULL;
    char **com = NULL;

    com = stock_command1(input, env);
    for (; com[i] != NULL; i++) {
        token = strtok(com[i], " \t\n");
        for (; token != NULL; j++) {
            args[j] = token;
            token = strtok(NULL, " \t\n");
        }
        args[j] = NULL;
        free(token);
        j = 0;
        cut_execute_command(input, args, env);
    }
    return 0;
}
