/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** A function that allocates memory
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *point = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i] != '\0'; i++)
        point[i] = src[i];
    point[i] = '\0';
    return point;
}
