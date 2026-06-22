/*
** EPITECH PROJECT, 2025
** functin
** File description:
** duplicate strings
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dupl = NULL;

    if (src == NULL)
        return NULL;
    dupl = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[i] != '\0'; i++)
        dupl[i] = src[i];
    dupl[i] = '\0';
    return dupl;
}

char *my_strndup(char const *src, size_t n)
{
    int i = 0;
    char *dupln = NULL;

    if (src == NULL)
        return NULL;
    dupln = malloc(sizeof(char) * (n + 1));
    for (; i < n; i++)
        dupln[i] = src[i];
    dupln[i] = '\0';
    return dupln;
}
