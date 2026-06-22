/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** my_strcat.c
*/

#include <stdio.h>
#include "my.h"

void my_strcat(char *dest, char *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0')
        a++;
    while (src[b] != '\0') {
        dest[a] = src[b];
        a++;
        b++;
    }
    dest[a] = '\0';
}
