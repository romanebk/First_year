/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** function
*/

#include <string.h>
#include "my.h"

void my_strncpy(char *dest, char const *src, int n)
{
    int nk = 0;

    while (nk < n) {
        dest[nk] = src[nk];
        nk++;
    }
    dest[nk] = '\0';
}
