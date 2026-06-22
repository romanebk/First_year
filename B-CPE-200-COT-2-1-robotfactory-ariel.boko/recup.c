/*
** EPITECH PROJECT, 2025
** recup
** File description:
** recup
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"

char *recup(char *str, int n)
{
    int i = 0;
    int k = 0;
    int j = 0;
    char *t = malloc(sizeof(char) * n + 1);

    if (!t)
        return NULL;
    while (str[i] != '"')
        i++;
    for (j = i + 1; str[j] != '"'; j++) {
        t[k] = str[j];
        k++;
    }
    t[k] = '\0';
    if (t == NULL || my_s(t) == 0)
        return NULL;
    return t;
}
