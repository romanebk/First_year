/*
** EPITECH PROJECT, 2025
** CECZCZ
** File description:
** CZDS
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    return 0;
}
