/*
** EPITECH PROJECT, 2024
** strcmp
** File description:
** comparaison
*/

#include "shell.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int retour = 0;
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
