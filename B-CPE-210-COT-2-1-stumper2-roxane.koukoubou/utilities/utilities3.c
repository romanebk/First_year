/*
** EPITECH PROJECT, 2025
** Robot Factory
** File description:
** PSU
*/

#include "../my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    for (; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[a] = '\0';
    return dest;
}

char *my_strdup(char *str)
{
    int size;
    char *dup;

    if (str == NULL)
        return NULL;
    size = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * size);
    if (!dup)
        return NULL;
    my_strcpy(dup, str);
    return dup;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    return dest;
}
