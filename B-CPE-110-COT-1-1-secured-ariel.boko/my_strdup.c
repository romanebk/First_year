/*
** EPITECH PROJECT, 2025
** vrfr
** File description:
** ferzecfze
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char *str)
{
    int i = 0;
    int len = 0;
    char *dest = NULL;

    len = my_strlen(str);
    dest = malloc(sizeof(char) * (len + 1));
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
