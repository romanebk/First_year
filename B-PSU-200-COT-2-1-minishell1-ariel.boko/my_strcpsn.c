/*
** EPITECH PROJECT, 2025
** function
** File description:
** remplace le \n par un \0
*/

#include "my.h"

void ommit(char *str1)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n')
            str1[i] = '\0';
    }
}
