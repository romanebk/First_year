/*
** EPITECH PROJECT, 2025
** sdfghjk
** File description:
** jhgfdsq
*/

#include "my.h"

int my_execve(char *input, char **env, char **args)
{
    int i = 0;
    int status = 0;
    pid_t pid = 0;

    pid = fork();
    if (pid == 0) {
        excution(input, env, args);
        exit(0);
    } else if (pid < 0) {
        perror("fork");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        WIFEXITED(status);
        signale(status);
    }
    return 0;
}
