/*
** EPITECH PROJECT, 2025
** function
** File description:
** recupère la valeur du path
*/

#include "my.h"

char *ret_path(char **env)
{
    char *str = NULL;
    int i = 0;
    char *token = NULL;

    if (env == NULL || !env)
        return NULL;
    for (; env[i] != NULL; i++) {
        if (env[i][0] == 'P' &&
            env[i][1] == 'A' &&
            env[i][2] == 'T' &&
            env[i][3] == 'H')
            break;
    }
    if (env[i] == NULL || !env[i] || i == 0)
        return NULL;
    str = my_strdup(env[i]);
    token = strtok(str, "=");
    token = strtok(NULL, "=");
    return token;
}

char *recup_home(char **env)
{
    char *str = NULL;
    int i = 0;
    char *token = NULL;

    if (env == NULL || !env)
        return NULL;
    for (; env[i] != NULL; i++) {
        if (env[i][0] == 'H' &&
            env[i][1] == 'O' &&
            env[i][2] == 'M' &&
            env[i][3] == 'E')
            break;
    }
    if (env[i] == NULL || !env[i] || i == 0)
        return NULL;
    str = my_strdup(env[i]);
    token = strtok(str, "=");
    token = strtok(NULL, "=");
    return token;
}

char *recup_old(char **env)
{
    char *str = NULL;
    int i = 0;
    char *token = NULL;

    if (env == NULL || !env)
        return NULL;
    for (; env[i] != NULL; i++) {
        if (env[i][0] == 'O' &&
            env[i][1] == 'L' &&
            env[i][2] == 'D' &&
            env[i][3] == 'P' &&
            env[i][4] == 'W' &&
            env[i][5] == 'D')
            break;
    }
    if (env[i] == NULL || !env[i] || i == 0)
        return NULL;
    str = my_strdup(env[i]);
    token = strtok(env[i], "=");
    token = strtok(NULL, "=");
    return token;
}
