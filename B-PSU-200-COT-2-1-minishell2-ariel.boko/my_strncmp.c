/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** Reproduce the behavior of the strncmp function
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int retour = 0;
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
