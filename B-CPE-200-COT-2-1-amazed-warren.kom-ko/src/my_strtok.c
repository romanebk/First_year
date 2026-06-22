/*
** EPITECH PROJECT, 2025
** function
** File description:
** have the behavior of the system command strtok
*/

#include "../include/my.h"

char *my_strchr(const char *s, int c)
{
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == c)
            return (char *)s;
        i++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

char *my_strtok(char *str, const char *delim)
{
    static char *last_pos = NULL;
    char *token;

    if (str != NULL)
        last_pos = str;
    if (last_pos == NULL)
        return NULL;
    while (*last_pos != '\0' && my_strchr(delim, *last_pos) != NULL)
        last_pos++;
    if (*last_pos == '\0')
        return NULL;
    token = last_pos;
    while (*last_pos != '\0' && my_strchr(delim, *last_pos) == NULL)
        last_pos++;
    if (*last_pos != '\0') {
        *last_pos = '\0';
        last_pos++;
    }
    return token;
}
