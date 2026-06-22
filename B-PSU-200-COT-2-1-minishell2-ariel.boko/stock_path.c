/*
** EPITECH PROJECT, 2025
** function
** File description:
** stocke les path dans un double tableau
*/

#include "my.h"

int lenght(char *str1, char *str2, char *str3)
{
    int b = my_strlen(str1) + my_strlen(str2) + my_strlen(str3) + 1;

    return b;
}

char *all_path(char **env, char *input, char **args)
{
    char *tab_path = NULL;
    char *token = NULL;

    token = strtok(ret_path(env), ":");
    if (token == NULL || my_strlen(token) == 0)
        return NULL;
    while (token != NULL) {
        tab_path = malloc(sizeof(char) *
            (lenght(token, args[0], "/")));
        my_strcpy(tab_path, token);
        concat_strings(tab_path, "/");
        concat_strings(tab_path, args[0]);
        if (access(tab_path, X_OK) == 0)
            return tab_path;
        else
            free(tab_path);
        token = strtok(NULL, ":");
    }
    free(token);
    return NULL;
}
