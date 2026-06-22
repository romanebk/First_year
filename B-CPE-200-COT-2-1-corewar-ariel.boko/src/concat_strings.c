/*
** EPITECH PROJECT, 2024
** concat_string
** File description:
** A function that concatenates two strings
*/

#include "../include/my.h"

char *concat_strings(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
