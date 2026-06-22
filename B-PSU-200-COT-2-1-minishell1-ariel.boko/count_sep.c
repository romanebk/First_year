/*
** EPITECH PROJECT, 2025
** function
** File description:
** compte le séparateur
*/

#include "my.h"

int count_line(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            a++;
    }
    return a;
}
