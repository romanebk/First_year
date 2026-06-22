/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** A function that allocates memory and copies the string given as argument
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *point = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i] != '\0'; i++)
        point[i] = src[i];
    point[i] = '\0';
    return point;
}
