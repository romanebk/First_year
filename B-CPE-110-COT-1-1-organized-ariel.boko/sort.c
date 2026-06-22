/*
** EPITECH PROJECT, 2024
** organised
** File description:
** quick_sort
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

int cut_sort(char **args, int i)
{
    if (args[i + 1] == NULL ||
        args[i + 1][0] != '-' ||
        args[i + 1][1] != 'r')
        return 84;
}

int sort(void *data, char **args)
{
    int i = 0;
    int valid_sort = 0;

    if (args[0] == NULL)
        return 84;
    for (; args[i] != NULL; i = i + 2) {
        if (my_strcmp(args[i], "NAME") == 0 ||
            my_strcmp(args[i], "ID") == 0 ||
            my_strcmp(args[i], "TYPE") == 0) {
            cut_sort(args, i);
            valid_sort = 1;
        } else {
            return 84;
        }
    }
    if (!valid_sort)
        return 84;
    return 0;
}
