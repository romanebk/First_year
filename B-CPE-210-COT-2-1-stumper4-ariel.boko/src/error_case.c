/*
** EPITECH PROJECT, 2025
** error.case
** File description:
** shortcut
*/

#include <stdio.h>
#include <stdlib.h>
#include "../my.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int count(char **av)
{
    int i = 0;

    while (av[i] != NULL) {
        i++;
    }
    return i;
}

int check(char *av)
{
    int b = 0;
    int c = my_strlen(av);

    for (int i = 0; av[i] != '\0'; i++) {
        if ((av[i] >= 48 && av[i] <= 57) || (av[i] == ' '))
            b++;
    }
    if (b == c)
        return 0;
    else
        return 1;
}
