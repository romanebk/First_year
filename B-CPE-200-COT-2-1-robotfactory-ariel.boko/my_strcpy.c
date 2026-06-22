/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** strcpy
*/

#include "my.h"

void my_strcpy(char *dest, char const *src)
{
    int nk = 0;

    while (src[nk] != '\0') {
        dest[nk] = src[nk];
        nk++;
    }
    dest[nk] = '\0';
}
