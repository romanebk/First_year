/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Function that copies a string into another string
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, size_t len)
{
    int i = 0;

    for (; src[i] != '\0' && i < len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
